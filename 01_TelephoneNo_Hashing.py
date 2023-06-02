"""Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up
clients telephone number. Make use of two collision handling techniques and compare them using number of
comparisons required to find a set of telephone numbers.
"""
table, tableq = {},{}
totl, totq = 0,0

b = int(input("Enter size of table: "))

#creating empty hash table
def create(b):
    for i in range(0,b):
        table[i] = None
        tableq[i] = None

#Linear probing insert function
def linsert(key, b):
    global totl
    hash = key % b
    flag = 0
    if(table[hash] == None):
        table[hash] = key
    else:
        for i in range(0,b):
            hash = (key + i) % b
            if(table[hash] == None):
                table[hash] = key
                totl += 1
                flag += 1
                break
        if (flag == 0):
            print("Table is Full or key in not probed.")

#Quadratic probing insert function
def qinsert(key, b):
    global totq
    hash = key % b
    if(tableq[hash] == None):
        tableq[hash] = key
    else:
        for i in range(0, int((b-1)/2)):
            hash = (key + (i*i))%b
            if(tableq[hash] == None):
                tableq[hash] = key
                totq += 1
                flag += 1
                break
        if(flag == 0):
            print("Table Full or Key is not probed")

#Linear probing search function
def lsearch(key, b):
    hash = key % b
    flag = 0
    if(table[hash] == None):
        print("Key: ", key, "is not present")
    else:
        for i in range(0,b):
            hash = (key+i) % b
            if(table[hash] == None):
                print("Key: ", key, "is not Present")
                flag += 1
                break
            elif(table[hash] == key):
                print("Key:", key, "is Present at location ", hash)
                flag += 1
                break
        if(flag == 0):
                print("Key: ", key, "is not Present")

#Quadratic probing search function
def qsearch(key, b):
    hash = (key + (i*i)) % b
    flag = 0
    if(tableq[hash] == None):
        print("Key: ", key, "is not Present")
    else:
        for i in range(0, int((b-1)/2)):
            hash = (key + (i*i)) % b
            if(tableq[hash] == None):
                print("Key: ", key, "is not Present")
                break
            elif(tableq[hash] == key):
                print("Key: ", key, "is present at location ", hash)
                flag += 1
                break
        if(flag == 0):
            print("Key: ", key, "is not Present")

#printing hash table
def printTable(b):
    print("Linearly Probed Table: ")
    for i in range(b):
        print(table[i], end = "|")
    
    print("\nQuadratically Probed Table: ")
    for i in range(b):
        print(tableq[i], end = "|")
        

#main function
create(b)

while(1):
    ch = int(input("\n1:Linear Probing \n2:Quadratic Probing \n3:Exit \nEnter your choice: "))
    #Linear Probing
    if(ch == 1):
        while(1):
            ch2 = int(input("\n1-Insert\n2-Search\n3-Print the table\n0-Back.\nEnter your choice: "))
            if(ch2 == 1):
                if(totl == b):
                    print("Table is Full")
                else:
                    key = int(input("Enter the key to be inserted: "))
                    linsert(key,b)
            elif(ch2 == 2):
                key = int(input("Enter the key to be searched: "))
                lsearch(key,b)
            elif(ch2 == 3):
                print("*******TABLE********")
                printTable(b)
            elif(ch == 0):
                print("GOING BACK")
                break
    #Quadratic Probing
    elif(ch == 2):
        while(1):
            ch2 = int(input("\n1-Insert\n2-Search\n3-Print the table\n0-Back.\nEnter your choice: "))
            if(ch2 == 1):
                if(totq == b):
                    print("Table is Full")
                else:
                    key = int(input("Enter the key to be inserted: "))
                    qinsert(key,b)
            elif(ch2 == 2):
                key = int(input("Enter the key to be searched: "))
                qsearch(key,b)
            elif(ch2 == 3):
                print("*******TABLE********")
                printTable(b)
            elif(ch == 0):
                print("GOING BACK")
                break
    #Exiting
    elif(ch == 3):
        print("Exiting")
        printTable(b)
        break
    else:
        print("Invalid choice")




              






