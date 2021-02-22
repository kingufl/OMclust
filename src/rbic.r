rm(list=ls(all=TRUE))
library(mclust)
data=read.csv("bic.csv",sep=" ",header=F)
names(data)=c("k","loglik","bic","boot")
n=22032839
kmersize=4
bic2=bic("EII", data$loglik, n, kmersize, data$k)
boxplot(bic2~data$k)