from cs50 import get_string, get_int
import re #regular expression operators
import sys

ccnum = (get_string("Number: "))

    #create a funciton that will test test the validity of the string and return bool
def is_valid_credit_card(number: str) -> bool: # This is a a type hint or type annotation.
    #It indicates that the function is expected to return a boolean value (True or False).

    pattern = r"^\d+$"  # Ensures the string contains only digits...see re manuals for explanation

    return bool(re.fullmatch(pattern, number))

    #check for validity by calling fxn with ccnum as parameter and setting other conditions
if not is_valid_credit_card(ccnum) or not (13 <= len(ccnum) <17):
    print("INVALID")
    sys.exit() #This replaces "return" when outside of the function

    #double every-other number starting at second-to-last, and then add single integer values together
def double_twos_and_add(ccnum: str):

    #Let's create an interable variable
    l = len(ccnum)

    #Let's initialize the variable of sum_twos to 0
    sum_twos = 0

    for i in range(l-2, -1, -2):
        #convert ccnum at index[i] to an int
        ccnum_int = int(ccnum[i])
        double_ccnum = 2 * ccnum_int

        #add integers with condition
        if double_ccnum > 9:
            double_sum = (double_ccnum // 10) + (double_ccnum % 10)
            sum_twos += double_sum
        else:
            sum_twos += double_ccnum

    #print(f"Double and sum of two's = {sum_twos}")
    return sum_twos

def sum_ones(ccnum: str):

    l = len(ccnum)
    sum_one = 0

    for i in range(l-1, -1, -2):

        ccnum_int = int(ccnum[i])
        sum_one += ccnum_int

    #print(f"Sum of one's = {sum_one}")
    return sum_one

#Initializing variables for final function
two = double_twos_and_add(ccnum)
one = sum_ones(ccnum)
l = len(ccnum)

def card_type(two, one, l, ccnum):
    if not (two + one) % 10 == 0:
        print("INVALID\n")

    if (l == 13 or l == 16) and ccnum[0] == "4":
        print("VISA")
    if l == 15 and ccnum[0] == "3" and ccnum[1] in ["4","7"]:
        print("AMEX")
    if l == 16 and ccnum[0] == "5" and ccnum[1] in ["1","2","3","4","5"]:
        print("MASTERCARD")
    else:
        print("INVALID\n")

    #Run the final function with all the parameters
card_type(two, one, l, ccnum)













    #sum every-other integer from last position

    #sum twos and ones

    #modulo 10 to check for validity & add commpany specific conditions for printing




