// CreateRunScoreTables.cpp : Defines the entry point for the console application.
//
// First lines of table look like:
/************************************
"Male Road Age Factors WMA and USATF, 2015*",,,,,,,,,,,,,,,,,,,,
Age,1 mile, 5 km,6 km,4 Mile,8 km,5 Mile,10 km,12 km,15 km,10 Mile,20 km,H. Mar,25 km,30 km,Marathon,50 km,50 Mile,100 km,150 km,100 Mile,200 km
Distance,1.609,5,6,6.4374,8,8.0467,10,12,15,16.09344,20,21.0975,25,30,42.195,50,80.46736,100,150,160.9344,200
OC sec,227,771,942,1014,1272,1279,1603,1942,2455,2640,3315,3503,4205,5110,7377,8970,16080,21360,36300,39850,52800
OC,0:03:47,0:12:59,0:15:42,0:16:54,0:21:12,0:21:19,0:26:43,0:32:22,0:40:55,0:44:00,0:55:15,0:58:23,1:10:05,1:25:10,2:02:57,2:29:30,4:28:00,5:56:00,10:05:00,11:04:10,14:40:00
5,0.6062,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056,0.6056
****************************/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

static char * male_table = "../MaleRoadStd2020.csv";
static char * female_table = "../FemaleRoadStd2020.csv";
static char oc[2][22][16];		// Hold open class times as strings oc[0] == male, oc[1] = female
static char age_factors[2][100][22][16];
static char* outputDir = "../RunScoreTables/";

static void nullOutCommas(char *p)
{
	// Turn commas into nulls
	for(;*p;p++) {
		if(*p == ',')
			*p = 0;
	}
	p--;
	*p = 0; // Turn terminating \n into null.
}

// Write out one table for RunScore
static void age_grade(char *filename,int index)
{
	static char *gender = "MF";
	static char fn[64];
	sprintf(fn, "%s%s", outputDir, filename);
	FILE *fp = fopen(fn,"wt");
	if(fp) {
		fprintf(fp,"M  %s\n",oc[0][index]);
		fprintf(fp,"F  %s\n",oc[1][index]);
		for(int i=0;i<2;i++) {
			for(int j=0;j<95;j++) {
				fprintf(fp,"%c %-3s %s\n",gender[i],age_factors[i][j][0],age_factors[i][j][index]);
			}
		}
		fclose(fp);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char buffer[512];
	// Read in tables
	char *tables[2] = {male_table,female_table};
	for(int i=0;i<2;i++) {
		const char *table = tables[i];
		FILE *fp = fopen(table,"rt");

		if(fp) {
			// Read title
			char *p = fgets(buffer,511,fp);
			// Read column headers
			p = fgets(buffer,511,fp);
			// Read Distance
			p = fgets(buffer,511,fp);
			// Read seconds
			p = fgets(buffer, 511, fp);
			// read open class times
			p = fgets(buffer,511,fp);
			nullOutCommas(p);
			char *pp = p;
			// Load up the open-class times
			// Note that the first one says "OC"
			int j=0;
			for(pp = p;strlen(pp);j++) {
				strcpy(oc[i][j],pp);
				pp += strlen(pp);
				pp++;
			}
			//
			// Load up the age-factors
			// Handle ages 5 through 99.
			for(int k=0;k<95;k++) {
				p = fgets(buffer,511,fp);
				if(p) {
					// We have read in all the distances (plus age)
					// Age,1 mile,5 km,6 km,4 Mile,8 km,5 Mile,10 km,12 km,15 km,10 Mile,20 km,H. Mar,25 km,30 km,Marathon,50 km,50 Mile,100 km,150 km,100 Mile,200 km
					// Turn commas into nulls
					nullOutCommas(p);
					for(pp = p,j = 0;strlen(pp) && j < 21;j++) {
						strcpy(age_factors[i][k][j],pp);
						pp += strlen(pp);
						pp++;
					}
				}
			}
			fclose(fp);
		}
	}

	// Create output directory
	mkdir(outputDir);

	// Everything is in memory. Write out files
	//    1      2    3    4      5    6      7     8     9     10      11    12     13    14    15       16    17      18     19     20       21
	//Age,1 Mile,5 km,6 km,4 Mile,8 km,5 Mile,10 km,12 km,15 km,10 Mile,20 km,H. Mar,25 km,30 km,Marathon,50 km,50 Mile,100 km,150 km,100 Mile,200 km

  age_grade("AgeGrade.1mi", 1);
  age_grade("AgeGrade.5k", 2);
	age_grade("AgeGrade.6k", 3);
	age_grade("AgeGrade.4mi", 4);
	age_grade("AgeGrade.8k", 5);
	age_grade("AgeGrade.5mi", 6);
	age_grade("AgeGrade.10k", 7);
	age_grade("AgeGrade.12k", 8);
	age_grade("AgeGrade.15k", 9);
	age_grade("AgeGrade.10mi", 10);
	age_grade("AgeGrade.20k", 11);
	age_grade("AgeGrade.hm",  12);
	age_grade("AgeGrade.25k", 13);
	age_grade("AgeGrade.30k", 14);
	age_grade("AgeGrade.26m", 15);
	age_grade("AgeGrade.42k", 15);
	age_grade("AgeGrade.50k", 16);
	age_grade("AgeGrade.50mi", 17);
	age_grade("AgeGrade.100k", 18);
	age_grade("AgeGrade.150k", 19);
	age_grade("AgeGrade.100mi", 20);
	age_grade("AgeGrade.200k", 21);
	return 0;
}
