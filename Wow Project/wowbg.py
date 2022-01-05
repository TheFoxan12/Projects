import random
import sys
import colorama
from colorama import Fore
from colorama import Back
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
letters = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
word = "theophile"
colors = [(Fore.BLUE, Back.BLUE), (Fore.GREEN, Back.GREEN), (Fore.RED, Back.RED), (Fore.YELLOW, Back.YELLOW), (Fore.MAGENTA, Back.MAGENTA), (Fore.CYAN, Back.CYAN), (Fore.WHITE, Back.WHITE)]
for i in range(500000):
	if not randomize:
		for letter in word:
			color = random.choice(colors)
			print(color[0] + Style.BRIGHT + color[1] + letter + Style.RESET_ALL, end='')
	else:
		for j in range(10):
			color = random.choice(colors)
			print(color[0] + Style.BRIGHT + color[1]  + random.choice(letters) + Style.RESET_ALL, end='')
