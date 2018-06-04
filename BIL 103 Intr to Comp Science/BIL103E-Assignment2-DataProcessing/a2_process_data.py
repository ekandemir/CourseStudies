# -*- coding: utf-8 -*-

#######################################################
### You can ignore the following lines of code.
### It loads the contents of a CSV file for you.
### The file's name should be a2_input.csv.
### You do NOT need to know how it works.
#######################################################
import csv

contents = []
with open("a2_input.csv") as input_file:
    for row in csv.reader(input_file):
        contents = contents + [row]

#######################################################
### Do your data processing below.
### The below code gives some examples
### of how to access the data.
### Print your results using the print function.
#######################################################
print ("<!DOCTYPE html>")
print ("<html lang='en'>")
print ("<head>")
print ("<title>CPU Performances</title>")
print ("<meta charset='UTF-8'>")
print ("</head>")
print ("<body>")
print ("<table style=\"border: 5px solid green; border-collapse: collapse; font-size: 18px; color: green;\">")
for i in range (0,210):
	print ("<tr style=\"border: 5px solid green; border-collapse: collapse; font-size: 18px; color: green;\">")
	print ("<th>")
	print (contents [i][1])
	print ("</th>")
	print ("<th>")
	print (contents [i][2])
	print ("</th>")
	print ("<th>")
	print (contents [i][3])
	print ("</th>")
	print ("<th>")
	print (contents [i][4])
	print ("</th>")
	print ("<th>")
	print (contents [i][5])
	print ("</th>")
	print ("<th>")
	print (contents [i][6])
	print ("</th>")
	print ("<th>")
	print (contents [i][7])
	print ("</th>")
	print ("<tr>")
print ("</table>")
sum_sys = 0
sum_mmin = 0
sum_mmax = 0
sum_cache = 0
sum_chmin = 0
sum_chmax = 0
gr_ave = 0
gr_ave_count = 0
for i in range (1,210):
	sum_sys = sum_sys + float(contents[i][2])
for i in range (1,210):
	sum_mmin = sum_mmin + float(contents[i][3])
for i in range (1,210):
	sum_mmax = sum_mmax + float(contents[i][4])
for i in range (1,210):
	sum_cache = sum_cache + float(contents[i][5])
for i in range (1,210):
	sum_chmin = sum_chmin + float(contents[i][6])
for i in range (1,210):
	sum_chmax = sum_chmax + float(contents[i][7])
for i in range (1,210):
	if int(contents[i][7])>sum_chmax/209:
		gr_ave= gr_ave+float(contents[i][7])
		gr_ave_count= gr_ave_count + 1



print ("<ul>")
print ("<li>")
print ("Sum of the sys"), sum_sys
print ("</li>")
print ("<li>")
print ("Sum of the mmins"), sum_mmin
print ("</li>")
print ("<li>")
print ("Sum of the mmaxs"), sum_mmax
print ("</li>")
print ("<li>")
print ("Sum of the caches"), sum_cache
print ("</li>")
print ("<li>")
print ("Sum of the chmins"), sum_chmin
print ("</li>")
print ("<li>")
print ("Sum of the chmaxs"), sum_chmax
print ("</li>")
print ("</ul>")

print ("<ul>")
print ("<li>")
print ("Average of the sys"), sum_sys/209
print ("</li>")
print ("<li>")
print ("Average of the mmins"), sum_mmin/209
print ("</li>")
print ("<li>")
print ("Average of the mmaxs"), sum_mmax/209
print ("</li>")
print ("<li>")
print ("Average of the caches"), sum_cache/209
print ("</li>")
print ("<li>")
print ("Average of the chmins"), sum_chmin/209
print ("</li>")
print ("<li>")
print ("Average of the chmaxs"), sum_chmax/209
print ("</li>")
print ("</ul>")
print ("<ul>")
print ("<li>")
print ("Average of the chmax values which are greater than average"), gr_ave/gr_ave_count
print ("</li>")
print ("</ul>")
reference='''
Description</br>

A relative performance measure and characteristics of 209 CPUs.</br><hr>
Usage</br>

cpus</br>

Format</br><hr><hr>

The components are:</br><hr>

name</br>

    &nbsp;manufacturer and model.</br><hr>
syct</br>

    &nbsp;cycle time in nanoseconds.</br><hr>
mmin</br>

    &nbsp;minimum main memory in kilobytes.</br><hr>
mmax</br>

    &nbsp;maximum main memory in kilobytes.</br><hr>
cach</br>

    &nbsp;cache size in kilobytes.</br><hr>
chmin</br>

    &nbsp;minimum number of channels.</br><hr>
chmax</br>

    &nbsp;maximum number of channels.</br><hr>
perf</br>

    &nbsp;published performance on a benchmark mix relative to an IBM 370/158-3.</br><hr>
estperf</br>

    &nbsp;estimated performance (by Ein-Dor & Feldmesser).</br><hr>

Source</br>

P. Ein-Dor and J. Feldmesser (1987) Attributes of the performance of central processing units: a relative performance prediction model. Comm. ACM. 30, 308–317.</br><hr>
References</br>

Venables, W. N. and Ripley, B. D. (2002) Modern Applied Statistics with S. Fourth edition. Springer.</br>

'''
print ("<p>")
print (reference)
print ("</p>")

print ("</body>")
