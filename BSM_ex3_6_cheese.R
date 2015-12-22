library(bayesm)
library(ggplot2)

#Load cheese data
data("cheese")

#How many weeks for each key (retailer + location)?
weeks_per_key<-as.data.frame(table(cheese$RETAILER))
hist(weeks_per_key$Freq,breaks=15)

#How many retailer-location keys?
print(paste(c('Number of Keys:',length(weeks_per_key$Var1)),collapse=" "))

#What is the distribution of coefficients (display) for a simple model (volume ~ display + price)?

##Capture all *within-key* regressions
key_regs<-with(cheese,
              by(cheese,RETAILER,function(x) lm(log(VOLUME)~DISP+log(PRICE),data=x)))
#key_regs<-with(cheese,
#               by(cheese,RETAILER,function(x) lm(log(VOLUME)~DISP+log(PRICE))))
print(class(key_regs[[1]]))

##Capture output summaries
key_reg_summ<-lapply(key_regs,summary)
print(key_reg_summ[[1]])
print(class(key_reg_summ[[1]]))
print(class(key_reg_summ))

##Create container to capture estimates and standard errors for DISP across all models
ci<-matrix(nrow=length(key_regs),ncol=3)

##Capture coefficients from each summary output (note that the matrix of results is flattened into a vector)
##(top to bottom, then left to right)
key_reg_coefs<-sapply(key_reg_summ,coef)
key_reg_coef_vecs<-sapply(key_reg_coefs,c)
print(key_reg_coefs[[1]])
print(class(key_reg_coefs[[1]]))
print(class(key_reg_coefs))

##Place estimates of DISP in the first column
#ci[,1]<-key_reg_coefs[2,]
ci[,1]<-sapply(key_reg_coef_vecs,function(x) x[[2]])

##Calculate lower (upper) bound of confidence interval and place in second (third) column
ci[,2]<-ci[,1]-1.96*sapply(key_reg_coef_vecs,function(x) x[[5]])
ci[,3]<-ci[,1]+1.96*sapply(key_reg_coef_vecs,function(x) x[[5]])

##Capture estimates in DF
key_est<-as.data.frame(ci)
names(key_est)<-c('est','ci_low','ci_hi')

##Capture names of each key
key_est$key<-names(sapply(key_reg_coef_vecs,function(x) x[[2]]))

##Generate base plot object
key_est_plot<-ggplot(key_est,aes(key,est,ymin=ci_low,ymax=ci_hi,color='r'))+
                geom_pointrange()+coord_flip()+
                ggtitle('Simple OLS: volume ~ display(shown) + price (by key)')
key_est_plot


