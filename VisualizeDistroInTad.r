Lamprey_AP2_A <- read.delim("~/Desktop/HonorsThesisCodeRepo/Honors-Thesis/Lamprey_AP2_A", header=FALSE)
View(Lamprey_AP2_A)
Lamprey_AP2_A_EXON <- read.delim("~/Desktop/HonorsThesisCodeRepo/Honors-Thesis/Lamprey_AP2_A_EXON", header=FALSE)
View(Lamprey_AP2_A_EXON)
Lamprey_TWIST_2 <- read.delim("~/Desktop/HonorsThesisCodeRepo/Honors-Thesis/Lamprey_TWIST_2", header = FALSE)
View(Lamprey_TWIST_2)
Lamprey_TWIST_2_EXON <- read.delim("~/Desktop/HonorsThesisCodeRepo/Honors-Thesis/Lamprey_TWIST_2_EXON", header = FALSE)
View(Lamprey_TWIST_2_EXON)
Lamprey_TWIST_3B <- read.delim("~/Desktop/HonorsThesisCodeRepo/Honors-Thesis/Lamprey_TWIST_3B", header = FALSE)
View(Lamprey_TWIST_3B)
Lamprey_TWIST_3B_EXON <- read.delim("~/Desktop/HonorsThesisCodeRepo/Honors-Thesis/Lamprey_TWIST_3B_EXON", header = FALSE)
View(Lamprey_TWIST_3B_EXON)

library(ggplot2)

ggplot(Lamprey_AP2_A, aes(V2)) + geom_histogram(bins = 20,fill = "red")
ggplot(Lamprey_AP2_A,aes(V2)) + geom_density()

ggplot(Lamprey_AP2_A_EXON, aes(V2)) + geom_histogram(bins=20)
ggplot(Lamprey_AP2_A_EXON, aes(V2)) + geom_density(alpha = .2)

ggplot(Lamprey_TWIST_2, aes(x=V2)) + geom_histogram(bins = 20)
ggplot(Lamprey_TWIST_2, aes(V2)) + geom_density(alpha = .2)

ggplot(Lamprey_TWIST_2_EXON, aes(V2)) + geom_histogram(bin = 20)
ggplot(Lamprey_TWIST_2_EXON, aes(V2)) +geom_density(alpha = .2)

ggplot(Lamprey_TWIST_3B, aes(V2)) + geom_histogram(bins = 20)
ggplot(Lamprey_TWIST_3B, aes(V2)) + geom_density(alpha = .2)

ggplot(Lamprey_TWIST_3B_EXON, aes(V2)) + geom_histogram(bins = 20)
ggplot(Lamprey_TWIST_3B_EXON, aes(V2)) + geom_density()

AP_2 <- density(Lamprey_AP2_A$V2) 
AP_2_EXON <- density(Lamprey_AP2_A_EXON$V2)
plot(AP_2_EXON)
lines(AP_2)

TWIST_2 <- density(Lamprey_TWIST_2$V2)
TWIST_2_EXON <- density(Lamprey_TWIST_2_EXON$V2)
plot(TWIST_2)
lines(TWIST_2_EXON)

TWIST_3B <- density(Lamprey_TWIST_3B$V2)
TWIST_3B_EXON <- density(Lamprey_TWIST_3B_EXON$V2)
plot(TWIST_3B_EXON)
lines(TWIST_3B)
