departmentList = [
	{ "name":"Computer Science", "_id":1, "phone#":"575-555-555", "course_offer":[3,4] },
	{ "name":"Math", "_id":2, "phone#":"575-555-444", "course_offer":[5,6] },
]

courseList = [	
	
	{ "_id":3, "name":"Introduction to Programming", "requisite":{"co-requisite":[4], "prerequisite": []}, "department_id": 1, "credit": 4, "description": "The course is designed to introduce problem solving and programming in C to Computer Science majors and those interested in applications of the language that involve dynamic structures and memory management. Topics include algorithm development; top-down design; modular programming; debugging; testing; control structures including selection, iteration and recursion; number systems; data representation; data types including arrays, strings."},

	{ "_id":4, "name":"Algorithms and Data Structures", "requisite":{"co-requisite":[6], "prerequisite": [3,5]}, "department_id": 1, "credit": 3, "description": "Fundamental data structures including linked lists, trees, hash tables, and graphs. Algorithms for sorting, searching, and other fundamental operations. Introduction to mathematical foundations for analysis of iterative and recursive algorithms and for bask correctness proofs. Analysis of algorithms. Implementation of selected algorithms using sound programming methodologies."},
	
	{ "_id":5, "name":"Calculus and Analytic Geometry I", "requisite":{"co-requisite":[], "prerequisite": []}, "department_id": 2, "credit": 4, "description": "Introduces the intuitive numerical and theoretical concepts of limits, continuity, differentiation and integration. Includes the study of extrema, curve sketching, and applications involving algebraic, exponential, logarithmic and trigonometric functions. Designed for mathematics, science and engineering majors."},
	
	{ "_id":6, "name":"Calculus and Analytic Geometry II", "requisite":{"co-requisite":[], "prerequisite": [5]}, "department_id": 2, "credit": 4, "description": "Continues course of study begun in Calculus I. Covers integration techniques, numerical integration, improper integrals, some differential equations, sequences, series and applications."},
	
]

	
