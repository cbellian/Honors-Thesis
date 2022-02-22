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
plot(AP_2_EXON, col = "red", xlab = "Location, Centered On Gene", ylab = "Proportion of Peaks",
      main = "Peak Frequency over TAD compared to Exon location")
lines(AP_2, col = "green")
legend("topleft",legend=c("Exon","Peak", "Gene Center"),col=c("red", "green","black"),pch = c(10,10,10), box.lty = 0)
abline(v = 14900000)

TWIST_2 <- density(Lamprey_TWIST_2$V2)
TWIST_2_EXON <- density(Lamprey_TWIST_2_EXON$V2)
plot(TWIST_2, col = "green", xlab = "Location, Centered On Gene", ylab = "Proportion of Peaks",
     main = "Peak Frequency over TAD compared to Exon location")
lines(TWIST_2_EXON, col = "red")
legend("topright",legend=c("Exon","Peak", "Gene Center"),col=c("red", "green", "black"),pch = c(10,10,10), box.lty = 0)
abline(v = 20498000)

TWIST_3B <- density(Lamprey_TWIST_3B$V2)
TWIST_3B_EXON <- density(Lamprey_TWIST_3B_EXON$V2)
plot(TWIST_3B_EXON, col = "red", xlab = "Location, Centered On Gene", ylab = "Proportion of Peaks",
     main = "Peak Frequency over TAD compared to Exon location")
lines(TWIST_3B, col = "Green")
legend("topleft",legend=c("Exon","Peak", "Gene Center"),col=c("red", "green", "black"),pch = c(10,10,10), box.lty = 0)
abline(v=13139709, col ="black")
