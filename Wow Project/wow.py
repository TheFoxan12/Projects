import random
import sys
import colorama
from colorama import Fore
from colorama import Style

try:
	randomize = sys.argv[1]
except IndexError:
	randomize = "True"

if randomize == "False":
	randomize = False
else:
	randomize = True

colorama.init()
letters = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
		   "w", "x", "y", "z"]
word = "theophile"
colors = [Fore.BLUE, Fore.GREEN, Fore.RED, Fore.YELLOW, Fore.MAGENTA, Fore.CYAN, Fore.WHITE]
for i in range(50000):
	if not randomize:
		for letter in word:
			print(random.choice(colors) + Style.BRIGHT + letter + Style.RESET_ALL, end='')
	else:
		for j in range(10):
			print(random.choice(colors) + Style.BRIGHT + random.choice(letters) + Style.RESET_ALL, end='')
