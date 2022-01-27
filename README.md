# Honors Thesis Cis-Regulatory Identification
## Shell scripts for command line tools
Adapters.sh is a shell script to run all 8 .fastq files through CutAdapt with the appropriate flags. It is divided across 4 paired sequence runs. <p>
Bowtie.sh runs Bowtie2 for each of the paired outputs using a very sensitive local alignment and then returns a single SAM file. <p>
## Files of outputs and parameters
CutAdapt returns JSON files with the parameters and trim results from the adapter removal process. <p>
Bowtie2 returns meta data as files with the alignment results. <p>
## Enhancer ID Code
This program takes in two bedGraph files and a RefSeq.bed file from the same organism and alignment index and then compares the contents to create an collection of their overlapping peak regions. When used with 2 different trials, it can identify all places where seperate treatments, such as H3K4me2 and H3K4me3 PTMs, overlap. The user can then input the accesion number of the gene of interest and the distance in either direction they would like to search. The output will is the location of each matching CRE that has overlap between both input files and that is within the bounds requested.
