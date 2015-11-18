class choro_map:
	'''This class provides tools for the generation of choropleth maps with matplotlib'''

	#Data manipulation
	import numpy as np
	import pandas as pd
	from pandas import Series,DataFrame

	#Spatial I/O
	import fiona

	#Geometric operations
	from shapely.geometry import shape,Polygon,MultiPolygon
	from shapely.ops import unary_union

	#Geometric plotting
	from descartes import PolygonPatch
	from matplotlib.collections import PatchCollection

	#Color
	from mpltools import color


	def shp_in(path,geo='geometry',fips='STATE_FIPS',name='STATE_ABBR'):
		'''Function reads in a shapefile and parses it to capture each jurisdiction's 
		polygon coordinates, FIPS code, and name.  It returns a dictionary holding 
		arrays for these items.  If the default field names are incorrect for a 
		particular shapefile, it returns the shapefile's meta info.  Given the FIPS
		component, it is clearly inspired by Census shapefiles, or derivatives thereof.'''

		#Open state shapefile
		shp=fiona.open(path)

		#Initiate iterator to read records
		poly=shp.next()

		#Create container for features, FIPS codes, and names
		poly_list=[]
		poly_fips_list=[]
		poly_name_list=[]

		try:
			#For each feature...
			for poly in shp:
			    #...throw the feature in the list...
			    poly_list.append(shape(poly[geo]))
			    #...the associated FIPS code....
			    poly_fips_list.append(poly['properties'][fips])
			    #...and the associated name in the other list
			    poly_name_list.append(poly['properties'][name])

			#Capture shp info in a dictionary
			shp_dict={'poly':poly_list,
					  'fips':poly_fips_list,
					  'name':poly_name_list}

			return shp_dict
		except:
			return shp.meta


	def colmap(df,var,idvar,colormap,start_col=.2):
	    '''Function reads in a variable and determines the colors corresponding to each
	    float value in the distribution.  It returns a dict mapping the color to each
	    corresponding idvar.'''

	    #Define min and max parameter values
	    minval=df[var].min()
	    maxval=df[var].max()
	    
	    #Generate color mapper
	    colmap=color.color_mapper((minval,maxval),cmap=colormap,start=start_col)
	    
	    #Generate containers for id values and colors
	    id_list=[]
	    col_list=[]
	    
	    #For each feature...
	    for idval in df[idvar]:
	        #...throw idval in the list...
	        id_list.append(idval)
	        #...and the corresponding color in the other list
	        col_list.append(colmap(df[df[idvar]==idval][var]))
	    
	    #Create mapping between idval and colors
	    col_dict=dict(zip(id_list,col_list))
	    return col_dict


	def col_plot(desired_polys,scope,var_colors,poly_dict,ax=ax):
	    '''Function accepts a list of polys, a bounding box, a dictionary
	    mapping poly IDs to colors, and an axis location.  It returns a 
	    choropleth map that plots the desired colors to associated polys.'''

	    #Restrict to relevant states in scope
	    poly_sub=[item for item in poly_dict.items() if item[0] in desired_polys]
	    
	    #Set scope of plot (manually cut off eastern extent of Alaska)
	    minx, miny, maxx, maxy = scope
	    if desired_polys==['02']:
	        maxx=-130.
	    w, h = maxx - minx, maxy - miny
	    ax.set_xlim(minx - 0.05 * w, maxx + 0.05 * w)
	    ax.set_ylim(miny - 0.05 * h, maxy + 0.05 * h)
	    
	    #Set aspect ratio
	    ax.set_aspect(1.2)
	    
	    #Create container for patches (neighborhoods in this context), locations, and names
	    patches=[]
	    patch_loc=[]
	    patch_nm=[]
	    
	    #For each poly...
	    for i,patch in enumerate(poly_sub):
	        #...assign a color from relevant color mapping...
	        col=var_colors[patch[0]]
	        #...if the poly is represented by a MultiPolygon...
	        if patch[1].geom_type != 'Polygon':
	            #...generate a patch representing each part of the poly and throw it in the list...
	            for patch_part in patch[1]:
	#                 patches.append(PolygonPatch(patch_part,fc=col,ec='#555555',lw=0.2,alpha=0.4,zorder=1,label=patch[0]))
	                patches.append(PolygonPatch(patch_part,fc=col,ec='w',lw=4,alpha=0.4,zorder=1,label=patch[0]))
	        else:
	            #...otherwise generate a patch representing the entire poly and throw it in the list...
	#             patches.append(PolygonPatch(patch[1],fc=col,ec='#555555',lw=0.2,alpha=0.4,zorder=1,label=patch[0]))
	            patches.append(PolygonPatch(patch[1],fc=col,ec='w',lw=4,alpha=0.4,zorder=1,label=patch[0]))
	        #...and capture the patch location and name
	        patch_loc.append((patch[1].centroid.x-.3,patch[1].centroid.y))
	        patch_nm.append(st_nm_dict[patch[0]])
	        
	    #Add the patches to the plot object en masse
	    ax.add_collection(PatchCollection(patches, match_original=True))
	        
	    #Remove ticks
	    ax.set_xticks([])
	    ax.set_yticks([])
	    ax.axis('off');