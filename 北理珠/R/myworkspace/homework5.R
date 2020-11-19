setwd('D:/git/lyz05/北理珠/R/myworkspace')#设置工作目录

data<-read.table("wdbc.txt",header = FALSE,na.strings = "NA",sep=',')
data
sum(is.na(data))
data<-subset(data,select = -V1)

train_sub <- sample(nrow(data),0.7*nrow(data))##随机无放回抽取
tdata <- data[train_sub,]
vdata <- data[-train_sub,]##

library(rpart)
dtree<-rpart(V2~.,data=tdata,method="class", parms=list(split="information"))
printcp(dtree)

