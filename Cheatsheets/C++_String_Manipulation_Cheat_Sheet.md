# C++ String Manipulation Cheat Sheet

## Declaration

``` cpp
string s = "hello";
string t(5, 'a');   // "aaaaa"
```

## Length

``` cpp
s.length();
s.size();
```

## Access

``` cpp
s[0];
s.at(0);
s.front();
s.back();
```

## Traversal

``` cpp
for(char c : s) {}
for(int i=0;i<s.size();i++) {}
```

## Append

``` cpp
s += "abc";
s.append("xyz");
s.push_back('!');
```

## Remove

``` cpp
s.pop_back();
s.erase(pos, len);
s.clear();
```

## Insert

``` cpp
s.insert(pos, "abc");
```

## Replace

``` cpp
s.replace(pos, len, "new");
```

## Substring

``` cpp
string sub = s.substr(pos, len);
```

## Find

``` cpp
s.find("abc");
s.rfind("abc");
if(s.find("abc") != string::npos) {}
```

## Compare

``` cpp
s == t;
s.compare(t);
```

## Reverse

``` cpp
reverse(s.begin(), s.end());
```

## Sort

``` cpp
sort(s.begin(), s.end());
```

## Count

``` cpp
count(s.begin(), s.end(), 'a');
```

## Unique (after sorting)

``` cpp
sort(s.begin(), s.end());
s.erase(unique(s.begin(), s.end()), s.end());
```

## Transform Case

``` cpp
transform(s.begin(), s.end(), s.begin(), ::toupper);
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

## String to Number

``` cpp
int x = stoi(s);
long long y = stoll(s);
float f = stof(s);
double d = stod(s);
```

## Number to String

``` cpp
string a = to_string(123);
```

## C-style String

``` cpp
const char* p = s.c_str();
```

## atoi (legacy)

``` cpp
int x = atoi(s.c_str());
```

## StringStream

``` cpp
stringstream ss("10 20 hello");
int a,b;
string str;
ss >> a >> b >> str;
```

## Concatenate

``` cpp
string c = s + t;
```

## Lexicographical Order

``` cpp
sort(v.begin(), v.end());
```

## Palindrome

``` cpp
string t = s;
reverse(t.begin(), t.end());
bool ok = (s == t);
```

## All Substrings

``` cpp
for(int i=0;i<s.size();i++)
    for(int len=1;i+len<=s.size();len++)
        cout << s.substr(i,len) << endl;
```

## Common Interview Functions

  Function           Purpose
  ------------------ -----------------------
  size(), length()   Length
  substr()           Extract substring
  find()             Find substring
  erase()            Delete
  insert()           Insert
  replace()          Replace
  append()           Append
  push_back()        Add character
  pop_back()         Remove last character
  reverse()          Reverse string
  sort()             Sort characters
  stoi(), stoll()    String → Number
  to_string()        Number → String
  c_str()            C-string conversion
  string::npos       "Not found" value
