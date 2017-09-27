import random
import sys

lst = random.sample(list(range(-1000, 1000)), int(sys.argv[1]))

for i in lst:
	print i,

