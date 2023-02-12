import pymongo
from data import departmentList
from data import courseList

#establish a connection to MongoDB 
client = pymongo.MongoClient("mongodb://127.0.0.1:27017/")

#create a new database, called "myDB"
db = client["myDB"]


#create two new collection, called "departmentCol" and "courseCatalogCol"
departmentCol = db["department"]
courseCatalogCol = db["courseCatalog"]

#check if collection exists and if empty.   
if departmentCol.count_documents({}) != 0:
	departmentCol.drop()
	departmentCol = db["department"]

if courseCatalogCol.count_documents({}) != 0:
	courseCatalogCol.drop()
	courseCatalogCol = db["courseCatalog"]

# Insert department records to the department collection
departmentCol.insert_many(departmentList)

# Insert course records to the courseCatalog collection
courseCatalogCol.insert_many(courseList)

####################################################################################
#Specification of data structure 
####################################################################################
#department data: 
#		{
# 			"name": "",
# 			"id": int,
# 			"phone#": "",
# 			"course_offer": []
#		}

#course data; 
#		{
# 			"name": "",
# 			"id": "",
#			"requisite": {
#					"co-requisite": [],
#					"prerequisite": []	
#					},  
#			"department_id": int,
#			"credit": "",
#			"description": ""
#		}


####################################################################################
# Q1: Find phone number 575-555-444 belongs to which department,
#
# Return the department name
#
# method find_one() is used in this case because we know a phone number can only belong
# to one department. Impossible to have more than one result. 

result = departmentCol.find_one({"phone#":"575-555-444"}, {"_id":0, "name":1})
print("Q1: " + str(result.get("name")))  

####################################################################################
# Q2: Find the prerequisite of course "Algorithms and Data Structures",
#
# Return the name of prerequisite course
result = courseCatalogCol.find_one({"name":"Algorithms and Data Structures"}, {"_id":0, "requisite.prerequisite":1})
prerequisite = result.get("requisite").get("prerequisite")
 
for course in prerequisite:
	result = courseCatalogCol.find_one({"_id": course}, {"_id":0, "name":1})
	print("Q2: " + result.get("name"))

####################################################################################
# Q3: Based on the course description, find which course(s) teach differential equations, 
#
# Return the name of department that offers the course. 

# method find() is used in this case because the topic 'differential equations' 
# can be taught by multiple calsses. We can not eliminate the possibility of having
# multiple matching objects.    
result = courseCatalogCol.find({"description":{'$regex':'differential equations'}}, {"_id":0, "department_id": 1})

for department in result:
	departmentName = departmentCol.find_one({"_id":department.get("department_id")}, {"_id":0, "name": 1})
	print("Q3: " + departmentName.get("name"))


client.drop_database('myDB')

