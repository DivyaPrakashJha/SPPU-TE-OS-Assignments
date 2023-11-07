#!/bin/sh

#Author : Divya Prakash

run=1
while [ $run -eq 1 ]
do	
	echo "\n*****Address Book*****"
	echo "\n-----Choose the desired option-----"
	echo "\n 1. Create an Address Book\n 2. View Address Book\n 3. Insert a record\n 4. Modify a record\n 5. Search record(s)\n 6. Delete a record\n 7. Exit"
	
	read option
	
	case $option in

		1) 
			touch addressBook.txt
			echo "Address Book Created Successfully\n"
		;;
	
		2)	
			echo "ID\t Name\t Mobile\t\t Address\n"
			cat addressBook.txt	
		;;
		
		3)
			echo "Enter the ID number : "
			read id
			
			grep $id addressBook.txt > temp.txt
			
			if [ -s temp.txt ]
			then
				echo "A person with the same ID number already exists!"
			else
				echo "Enter the Name : "
				read name
				echo "Enter the Mobile Number : "
				read mob
				echo "Enter the Address : "
				read address
				
				echo "$id\t $name\t $mob\t $address" >> addressBook.txt	
			fi
			
			rm temp.txt
		;;
		
		4)
			echo "Enter the ID number of the person whose details you want to modify : "
			read id
			
			grep $id addressBook.txt > temp.txt
			
			if [ -s temp.txt ]
			then
				echo "Enter the Name "
				read name
				echo "Enter the Mobile Number : "
				read mob
				echo "Enter the Address : "
				read address
				
				grep -v $id addressBook.txt > new.txt
				echo "$id\t $name\t $mob\t $address" >> new.txt
				mv new.txt addressBook.txt
			else
				echo "No matching record for the given ID exists!"
			fi
		;;
		
		5)
			echo "Enter any detail of the person you want to search for : "
			read keyword
			
			grep $keyword addressBook.txt > temp.txt
			
			if [ -s temp.txt ]
			then
				cat temp.txt
			else
				echo "No matching record for given detail!"
			fi
			
			rm temp.txt
		;;
		
		6)
			echo "Enter the ID number of the person you want to delete : "
			read id
			
			grep $id addressBook.txt > temp.txt
			
			if [ -s temp.txt ]
			then
				grep -v $id addressBook.txt > new.txt
				mv new.txt addressBook.txt
			else
				echo "No matching record for given ID exists!"
			fi
			
			rm temp.txt
		;;
		
		7)
			break;
		;;
		
	esac
done

