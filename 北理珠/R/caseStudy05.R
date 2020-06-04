url<-"D:\\git\\lyz05\\北理珠\\R"
setwd(url) 
protein<-read.table("protein.txt", sep=" ", header=TRUE)
protein
summary(protein)

#Data preprocessing
v<-colnames(protein)[-1]
pmatrix<-scale(protein[,v])
pmatrix

#Clustering
k<-5
pclusters<-kmeans(pmatrix, k, nstart=10, iter.max=10)
summary(pclusters)
#Resaults
groups<-pclusters$cluster
print_clusters <- function(labels,k)
{
  for(i in 1:k)
  {
    print(paste("聚类",i))
    print(protein[labels==i,
                  c("Country","RedMeat","Fish","Fr.Veg")])
  }
}
print_clusters(groups,k)

#聚类绘图
png(file="cluster.png")
library("cluster")
clusplot(protein[,-1], groups, main='2D representation of the Cluster solution',
         color=TRUE, shade = TRUE, labels = 2, lines = 0)
dev.off()

#红肉白肉绘图
plot(protein$RedMeat,protein$WhiteMeat, type="n", xlim=c(3,19), xlab="Red Meat",ylab="White Meat")
text(x=protein$RedMeat,y=protein$WhiteMeat, labels = protein$Country,col=groups+1)