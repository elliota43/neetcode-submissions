type DynamicArray struct {
    Capacity int 
    Data []int
}

func NewDynamicArray(capacity int) *DynamicArray {
    return &DynamicArray{
        Capacity: capacity,
        Data: make([]int, 0, capacity),
    }
}

func (da *DynamicArray) Get(i int) int {
    return da.Data[i]
}

func (da *DynamicArray) Set(i int, n int) {
    da.Data[i] = n
}

func (da *DynamicArray) Pushback(n int) {
    da.Data = append(da.Data, n)
}

func (da *DynamicArray) Popback() int {
    idx := len(da.Data) - 1
    el := da.Data[idx]
    da.Data = da.Data[:idx]
    return el
}

func (da *DynamicArray) resize() {
    currentCap := cap(da.Data)
    newData := make([]int, 0, currentCap * 2)
    da.Data = append(newData, da.Data[:]...)
}

func (da *DynamicArray) GetSize() int {
    return len(da.Data)
}

func (da *DynamicArray) GetCapacity() int {
    return cap(da.Data)
}
