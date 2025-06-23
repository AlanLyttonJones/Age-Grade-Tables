# Age-Grade-Tables
Tables for grading road-running performances based on gender and age. 

## Background
In 1989 the National Masters News and the World Association of Veteran Athletes (WAVA) compiled a booklet, Masters Age-Graded Tables, of tables for grading athletic performances based on sex and age. These tables covered all standard track and field events plus standard long distance running events and race-walking events. They only covered ages 30 and above. These tables were compiled by a committee composed of Rodney Charnock, Peter Mundle, Charles Phillips, Gary Miller, Bob Fine, Rex Harvey, Phil Mulkey, Bob Stone, Mike Tymn, Christel Miller, Phil Raschker, and Al Sheahen.
In 1994 the tables were updated and were extended to ages 8 through 19 in Age-Graded Tables, National Masters News, P.O. Box 2372, Van Nuys, CA 91404.
## New Method developed
In 2002 Alan Jones scored a race in which it seemed to him that the younger runners were not being treated fairly. He began, at that time, to create new tables using a new method of fitting curves to the data. After some months he began to work with Rex Harvey.
Working closely with Rex Harvey through the spring of 2004, Alan and Rex developed new tables for track distance running and road races up to 200 km. 
# 2004/2006 (2002) Tables
* The first tables done by Alan Jones and Rex Harvey were called the WMA 2002 tables. However, work on the male tables was completed in 2004 and the female in 2006 so we refer to them as the male 2004 and female 2006 tables.
* These tables include both the in-stadium events and road events.
# 2010 Long Distance Running Tables
* In 2009, information was provided that indicated that the female tables for older runners at the longer distances were too soft. Several runners were obtaining percentage performances of over 100%. The female tables were then adjusted based on recent data provided by Marian and Don Lein. Don is the USATF Masters Long Distance Running Chair.
* The 2010 tables were created in early 2010, and were approved by both WMA and by United States USA Track & Field (USATF). They are available here. 
* These tables are called the WMA/USATF 2010 tables.
* The male tables were not changed since their completion in 2004.
* The track tables have not changed since the 2004/2006 tables.
# 2015 Long Distance Running Tables
* When a new world record, 2:02:57, for the men's Marathon was set on September 28, 2014 at the Berlin Marathon by 30-year-old Denis Kimetto of Kenya, it generated a blog by Robert James Reese from Runner's World magazine. He suggested that it may be time to update the age-grade tables. This inspired us to check on how many times had changed in the almost ten years since the men's tables were established and the almost five years since the women's tables were updated.
* Ken Young from the Association of Road Racing Statisticians was helpful in evaluating the 2015 tables.
* The 2015 tables were approved in January 2015 by both the USATF Masters Long Distance Running committee chaired by Don Lein and by the WMA.
# 2020 Long Distance Running Tables
* Unfortunately, Ken Young died in 2018. Tom Bernard took on the task of updating the single-age bests.
* Working with Tom Bernhard, 2020 standards have been developed. The standards are included in this repository in the '2020 Files" directory: FemaleRoadStd2020.xlxs and MaleRoadStd2020.xlxs.
* In addition, the working files that produced the standards are included in the '2020 Files' directory: maleRoad2020.xlxs and femaleRoad2020.xlxs. A document in the docs folder, Creating Road Running Age Tables.docx, describes how the tables are produced. This will allow someone to fork this repository and create new age-group tables for, say, 2025.
* Another document in the folder docs, Evaluating 2020 Standards Against 2019 Rankings.docx, compares top performances by masters athletes using the 2015 standards and the 2020 standards. The comparisons were done by Tom Bernhard. Each comparison is followed with an explanation of the differences and, in all cases except the road mile, includes a graph showing the differences between the 2015 and 2020 standards.
* The 2020 tables were approved on May 20, 2020 by the Masters Long Distance Running Council (MLDR) of [USA Track and Field Federation](http://usatf.org)
* Here is a link to an age-grade performance calculator that uses these standards. It is maintained by Howard Grubb at [USAT&F MLDR Road age-grading calculator 2020](http://howardgrubb.co.uk/athletics/mldrroad20.html).
# Mt. Washington bike race tables.
* In December 2022, at the request of Trish Tarter and Bill Teschek, age-grade tables were produced for the Mt. Washington uphill climb bicycle race.
# 2025 Long Distance Running Tables
* Again, working with Tom Bernhard who provided the single-age bests, the 2025 standards were developed. The standards are included in the GitHub repository in the '2025 Files" directory: FemaleRoadStd2025.xlxs and MaleRoadStd2025.xlxs.
* The working files that produced the standards are included: maleRoad2025.xlxs and femaleRoad2025.xlxs.
* For the 2025 tables, an improved interpolation scheme for computing age factors for the distances other than 5 km, 10 km, Half-Marathon, and Marathon. The standards are developed for 5 km, 10 km, Half-Marathon, and Marathon. Then the standards at all the other distances are computed by interpolation. For example, for the 6 km distance, the difference between the log of 10 and the log of 5 is divided into the difference between the log of 6 and the log of 5. This number, which we call u, is between zero and one. For example:
* u = (log 6 - log 5) / (log 10 - log 5)
* It is used in the interpolation. Again, for the 6 km standards. The standard for each age is computed by taking the standard for the age at 5 km, S5, and the standard for that age at 10 km, S10 and using the following formula to compute the standard at 6 km, S6.
* S6 = S5 * (1 – u) + S10*u
* The 2025 tables were approved on 2025-01-10 by the Masters Long Distance Running Council (MLDR) of USA Track and Field Federation

