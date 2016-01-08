use http://www.stata-press.com/data/r7/school.dta, clear
biprobit (private = years logptax loginc) (vote=years logptax loginc)
