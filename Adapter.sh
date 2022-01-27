#!/bin/bash

cutadapt -q 20 --cores 12 -a file:adapters.fasta  -A file:adapters.fasta -o /Users/cameronbellian/Desktop/stg21_me3.1.fastq -p /Users/cameronbellian/Desktop/stg21_me3.2.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage21_me3_1_S1_L003_R1_001.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage21_me3_1_S1_L003_R2_001.fastq

cutadapt -q 20 --cores 12 -a file:adapters.fasta  -A file:adapters.fasta -o /Users/cameronbellian/Desktop/stg22_me2.1.fastq -p /Users/cameronbellian/Desktop/stg22_me2.2.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage22_me2_3_S3_L003_R1_001.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage22_me2_3_S3_L003_R2_001.fastq

cutadapt -q 20 --cores 12 -a file:adapters.fasta  -A file:adapters.fasta -o /Users/cameronbellian/Desktop/stg22_me2_2.1.fastq -p /Users/cameronbellian/Desktop/stg22_me2_2.2.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage22_me2_5_S5_L003_R1_001.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage22_me2_5_S5_L003_R2_001.fastq

cutadapt -q 20 --cores 12 -a file:adapters.fasta  -A file:adapters.fasta -o /Users/cameronbellian/Desktop/stg22_me3.1.fastq -p /Users/cameronbellian/Desktop/stg22_me3.2.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage22_me3_4_S4_L003_R1_001.fastq /Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta/Stage22_me3_4_S4_L003_R2_001.fastq

#/Users/cameronbellian/Desktop/2020_CT_Seq_Run/Seq_Data/Unzipped_fasta
