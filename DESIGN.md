# Language Design

#### Variables

```
<type> <var-name> = <value>

// examples

int intVar = 10
float floatVar = 10.1
string s = "hello"
char c = 'c'
```

#### Conditionals

##### if-elif-else
Follows C++ template, with ``elif`` replacing ``else if``

```
if (condition) {

} elif (condition) {

} else {

}
```

---
#### Loops

##### For Loops
Again, follows C++ style. Need to state increment variable type.

```
for int i=start; i<end; i++ {
    // statements go here
}
```

##### While Loops
Follows C++ style. Need to state the condition with parenthesis.

```
while (condition) {
    // statements go here
}
```
---

#### Functions
```
func <name>(...<args>...) <return-type> {
    // statements/expressions go here

    return <...>
}
```

---

#### Arrays
```
# Similar to Python, where we initialize the type and name of array

// Initializing an array
<type> <name> = []

int arr = []
// arr = []
arr.append(10)
// arr = [10]

```
