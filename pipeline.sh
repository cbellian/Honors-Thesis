#Trim
cd /Users/cameronbellian/miniconda3/
#cutadapt --nextseq-trim=20 -o out.fastq input.fastq
cutadapt -q 20 --cores 12 -a file:adapters.fasta  -A file:adapters.fasta -o /Users/cameronbellian/Desktop/stg22_me2.1.fastq -p /Users/cameronbellian/Desktop/stg22_me2.2.fastq /Users/cameronbellian/Desktop/stage22_me2_r1.fastq /Users/cameronbellian/Desktop/stage22_me2_r2.fastq

#Align Local
/Users/cameronbellian/Desktop/Lab_BioInfo_tools/bowtie2-2.4.4-macos-x86_64/bowtie2 --local --very-sensitive --no-mixed --no-discordant --phred33 -I 10 -X 700 -x/Users/cameronbellian/Desktop/2017_Index -1 /Users/cameronbellian/Desktop/stg22_me2.1.fastq -2 /Users/cameronbellian/Desktop/stg22_me2.2.fastq -S /Users/cameronbellian/Desktop/stg22_me2_align_out -p 12
#Align full
/Users/cameronbellian/Desktop/Lab_BioInfo_tools/bowtie2-2.4.4-macos-x86_64/bowtie2 --very-sensitive --no-mixed --no-discordant --phred33 -I 10 -X 700 -x/Users/cameronbellian/Desktop/2017_Index -1 /Users/cameronbellian/Desktop/stg22_me2.1.fastq -2 /Users/cameronbellian/Desktop/stg22_me2.2.fastq -S /Users/cameronbellian/Desktop/stg22_me2_align_out -p 12
#Convert Sam To Bed #using bedops and samtools
convert2bed -i sam </Users/cameronbellian/Desktop/stg22_me2_align_out >/Users/cameronbellian/Desktop/stg22_me2.bed
#bed to bedgraph  https://www.biostars.org/p/176179/
bedtools genomecov -bg -i /Users/cameronbellian/Desktop/stg22_me2.bedgraph -g /Users/cameronbellian/Desktop/Enhancer\ ID/EnhancerIDproj/Lamprey_CHr_size  > /Users/cameronbellian/Desktop/stg22_me2_copy_new.bedgraph
#input into SEACR with n of 1

#https://blog.gene-test.com/create-bigwig-files/
bamCoverage -b Seqdata.bam -o Seqdata.bigWig


#MACS2
MACS2 callpeak -t /Users/cameronbellian/Desktop/stg22_me2.bed -n stg22_me2 --outdir /Users/cameronbellian/Desktop
