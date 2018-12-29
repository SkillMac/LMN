import os

for key in os.environ:
	print(key+'', os.environ[key]+'')

# print(os.getenv("WindowsSdkDir"))