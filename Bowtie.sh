#!/bin/bash

/Users/cameronbellian/Desktop/Lab_BioInfo_tools/bowtie2-2.4.4-macos-x86_64/bowtie2 --local --very-sensitive --no-mixed --no-discordant --phred33 -I 10 -X 700 -x/Users/cameronbellian/Desktop/2017_Index -1 /Users/cameronbellian/Desktop/stg21_me3.1.fastq -2 /Users/cameronbellian/Desktop/stg21_me3.2.fastq -S /Users/cameronbellian/Desktop/stg21_me3_align_out -p 12 --met-file /Users/cameronbellian/Desktop/stg21_me3_meta

/Users/cameronbellian/Desktop/Lab_BioInfo_tools/bowtie2-2.4.4-macos-x86_64/bowtie2 --local --very-sensitive --no-mixed --no-discordant --phred33 -I 10 -X 700 -x/Users/cameronbellian/Desktop/2017_Index -1 /Users/cameronbellian/Desktop/stg22_me2.1.fastq -2 /Users/cameronbellian/Desktop/stg22_me2.2.fastq -S /Users/cameronbellian/Desktop/stg22_me2_align_out -p 12 --met-file /Users/cameronbellian/Desktop/stg22_me2_meta

/Users/cameronbellian/Desktop/Lab_BioInfo_tools/bowtie2-2.4.4-macos-x86_64/bowtie2 --local --very-sensitive --no-mixed --no-discordant --phred33 -I 10 -X 700 -x/Users/cameronbellian/Desktop/2017_Index -1 /Users/cameronbellian/Desktop/stg22_me2_2.1.fastq -2 /Users/cameronbellian/Desktop/stg22_me2_2.2.fastq -S /Users/cameronbellian/Desktop/stg22_me2_2_align_out -p 12 --met-file /Users/cameronbellian/Desktop/stg22_me2_2_meta

/Users/cameronbellian/Desktop/Lab_BioInfo_tools/bowtie2-2.4.4-macos-x86_64/bowtie2 --local --very-sensitive --no-mixed --no-discordant --phred33 -I 10 -X 700 -x/Users/cameronbellian/Desktop/2017_Index -1 /Users/cameronbellian/Desktop/stg22_me3.1.fastq -2 /Users/cameronbellian/Desktop/stg22_me3.2.fastq -S /Users/cameronbellian/Desktop/stg22_me3_align_out -p 12 --met-file /Users/cameronbellian/Desktop/stg22_me3_meta
