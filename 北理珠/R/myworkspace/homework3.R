setwd('D:/git/lyz05/北理珠/R/myworkspace')#设置工作目录

attach(iris)
round(mean(Sepal.Length),2)
summary(iris)
plot(Sepal.Length,Sepal.Width)
plot(Species)
plot(Species,Sepal.Length)
plot(iris)

attach(iris)
plot(Sepal.Length[Species=="setosa"],Petal.Length[Species=="setosa"],pch=1,col="black",xlim=c(4,8),ylim=c(0,8),main="Classified scatter plot",xlab="Slen",ylab = "PLen")
points(Sepal.Length[Species=="virginica"],Petal.Length[Species=="virginica"],pch=3,col="green")
points(Sepal.Length[Species=="versicolor"],Petal.Length[Species=="versicolor"],pch=2,col="red")
legend(4,8,legend=c("setosa","versicolor","virginica"),col=c(1,2,3),pch=c(1,2,3))

library(ggplot2)
p<-ggplot(data=iris,mapping = aes(x=Sepal.Length,y=Sepal.Width))
p + geom_point(aes(colour=Species))