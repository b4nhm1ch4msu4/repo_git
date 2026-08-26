## type alignment guarantees

> [!NOTE]
> (starting) memory addr % N(T) == 0
    T: type name
    N: type alignment guarantee of type T

- FIELD alignment guarantee     (field of a struct)
- GENERAL alignment guarantee   (others case)

```go
// compile time
general_alignment_guarantee := unsafe.Alignof(t)
field_alignment_guarantee := unsafe.Alignof(x.t)    // x is struct containt field t

// run time
general_alignment_guarantee := reflect.TypeOf(t).Align()
field_alignment_guarantee := reflect.TypeOf(t).FieldAlign()
```

> [!NOTE]
> general_alignment_guarantee == field_alignment_guarantee (at Go compiler current version `v1.25.n`)

> [!NOTE]
> 1. For a variable x of any type: unsafe.Alignof(x) is at least 1.
> 2. For a variable x of struct type: unsafe.Alignof(x) is the largest of all the values unsafe.Alignof(x.f) for each field f of x, but at least 1.
> 3. For a variable x of array type: unsafe.Alignof(x) is the same as the alignment of a variable of the array's element type.

### standard Go compiler

type                      alignment guarantee
------                    ------
bool, uint8, int8         1
uint16, int16             2
uint32, int32             4
float32, complex64        4
arrays                    depend on element types
structs                   depend on field types
other types               size of a native word
