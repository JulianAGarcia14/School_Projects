#!/usr/bin/python3

# Julian Garcia

import pymongo
from data import bookList
from data import authorList

#establish a connection to MongoDB 
client = pymongo.MongoClient("mongodb://127.0.0.1:27017/")

#create a new database, called "myDB"
db = client["myDB"]

#create two new collection, called "books" and "authors"
bookCol = db["books"]
authorCol = db["authors"]

#check if collection exists and if empty.   
if bookCol.count_documents({}) != 0:
	bookCol.drop()
	bookCol = db["books"]

if authorCol.count_documents({}) != 0:
	authorCol.drop()
	authorCol = db["authors"]
	
# Insert author records to the books collection
authorCol.insert_many(authorList)

# Insert book records to the books collection
bookCol.insert_many(bookList)

####################################################################################
#Specification of JSON data structure 
####################################################################################
#JSON structure for typical author data: 
#{
# "_id": "",
# "Name": "", 
# "Biography": {
# 		"About the Author": "", 
#		"Country":"", 
#		"Age": Int
#		}, 
# "Publication Count": Int
#}

#JSON structure for typical book data; 
#{
#"_id": "",
#"Title":"", 
#"ISBN" :"", 
#"Page Count": Int,
#"thumbnailUrl": "",
#"Description" : {
#		"Short Description": "",
#		"Long Description": ""
#		}, 
#"Status":"", 
#"Authors" : [], 
#"Categories" : [] 
#}


####################################################################################
#Question 1: find the author of the book "Android in Action, Second Edition"
#
#Return the author's name or names.				      
####################################################################################

result = bookCol.find_one({"Title":"Android in Action, Second Edition"}, {"Authors": 1 })
authlist = result.get("Authors")
print("Question 1:")
for names in authlist:
	result2 = authorCol.find_one({"_id":names}, {"Name": 1 })
	print(str(result2.get("Name")))  

####################################################################################
# Question 2: find out which book(s) is an (are) an anthology.                                
# (Search using the word 'anthology', the word will appear under 'Long Description'.)
#
# Return the title of the book(s).			      
####################################################################################
#Searches Long and Short Descriptions for 'anthology'

print("Question 2:")
for x in bookCol.find():
	result = bookCol.find_one({"_id":x.get("_id")}, {"_id":0})
	ans = result.get("Description").get("Long Description")
	if ans.find('anthology') != -1:
		print(str(result.get("Title")))





####################################################################################          
# Question 3: Among the authors of the book "Unlocking Android", which author is a            
# managing partner at Twin Technologies LLC.                                                  
#                                                                                             
# (Does the 'About the Author' field of the author contain the string                         
# 'Managing Partner' followed by 'Twin Technologies LLC'?)                                    

# Return his/her name and biography.                                                          

# Hint:                                                                                       
# Divide the problem into two steps:                                                          
# Step I: get a list of authors of the book from the book-collection (similar to Question 1).
# Step II: iterate through that list (using a for-loop) executing                             
# a query that searches for those two strings                                                 
# In Python, consider import re (i.e., the regular expressions library)                       
# and the re.compile() method to generate more complex regex.   
####################################################################################
result = bookCol.find_one({"Title":"Unlocking Android"}, {"Authors": 1 })
authlist = result.get("Authors")
print("Question 3:")
for names in authlist:
	result2 = authorCol.find_one({"_id":names})
	answer = result2.get("Biography").get("About the Author")
	if answer.find('Managing Partner') != -1 and answer.find('Twin Technologies LLC') != -1:
		print(str(result2.get("Name")))





client.drop_database('myDB')
