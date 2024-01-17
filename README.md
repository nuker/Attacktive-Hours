# Attacktive-Hours
Reading the active hours of a local windows computer though registry keys.

# DISCLAIMER
- **Please make sure you have mingw installed on your system if not
makefile will not be able to locate it to compile**

- **Alternatively you can use this code to write your own version and compile it in visual studio**

## To run

**Clone the repo**
```bash
git clone https://github.com/nuker/Attacktive-Hours.git .
```
**Go into the directory**
```
cd Attacktive-Hours
```
**Type "make" in the terminal to compile**
```bash
make
```
**You should see the compiled binary in bin/**
```
ls -la /bin
```

# Run
**To run the file you can start a python server on your UNIX machine and download it from a windows virtual machine**

**Python http server**

```python
python3 -m http.server -b [IP] [PORT]
```
**Download from http://[IP]:[PORT]**
