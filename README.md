# Honors Thesis CRE ID
## Shell scripts for command line tools
Adapters.sh is a shell script to run all 8 .fastq files through CutAdapt with the appropriate flags. It is divided across 4 paired sequence runs. <p>
Bowtie.sh runs Bowtie2 for each of the paired outputs using a very sensitive local alignment and then returns a single SAM file. <p>
## Files of outputs and parameters
CutAdapt returns JSON files with the parameters and trim results from the adapter removal process. <p>
Bowtie2 returns meta data as files with the alignment results. <p>
