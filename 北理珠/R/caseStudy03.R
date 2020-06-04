url_string<-"D:/git/lyz05/北理珠/R"
setwd(url_string)
#
#英制转公制
rm(list = ls())
women<-data.frame(women$height*2.54,women$weight/2.2046)
women<-round(women,0)
colnames(women)<-c("height","weight")
women
write.table(women,file = "women.txt",sep=" ",row.names = FALSE,quote = FALSE)

women #打印woman数据集
f<-lm(weight~height, data=women) 
f	#y=a*x+b => weight=3.45*height-87.52
summary(f)
fitted(f)
residuals(f)

png(file="linearregression.png")
attach(women)
plot(height,weight,col="blue",main="Height & Weight Regression",
     xlab="身高(cm)",ylab="体重(kg)")
abline(f)
dev.off()

#Find weight of a person with height 172 cm.
a <- data.frame(height = 172)
result <- predict(f,a)
print(round(result,0))