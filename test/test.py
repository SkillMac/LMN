import os
import sys

# print([x for x in os.environ])

print( [p for p in os.getenv("INCLUDE").split(";")])

print( os.path.join(os.getenv("WindowsSdkDir"), "Include") )
# print( [p for p in os.getenv("LIB").split(";")])