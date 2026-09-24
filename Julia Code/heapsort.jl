function heapify!(arr, size, root)

    largest = root
    left = 2 * root + 1
    right = 2 * root + 2

    if left < size && arr[left + 1] > arr[largest + 1]
        largest = left
    end

    if right < size && arr[right + 1] > arr[largest + 1]
        largest = right
    end

    if largest != root

        temp = arr[root + 1]
        arr[root + 1] = arr[largest + 1]
        arr[largest + 1] = temp

        heapify!(arr, size, largest)

    end

end


function heapSort!(arr, size)

    for i in (size ÷ 2 - 1):-1:0

        heapify!(arr, size, i)

    end

    for i in (size - 1):-1:1

        temp = arr[1]
        arr[1] = arr[i + 1]
        arr[i + 1] = temp

        heapify!(arr, i, 0)

    end

end


function main()
    file = open(#=file name=#, "w")
    println(file, "Run,Time (nanoseconds)")
    for i in 1:10

        # Full original array goes here unchanged
        
        arr = #array
        
        size = length(arr)

        # Start timer
        start = time_ns()

        # Sort array
        heapSort!(arr, size)

        # Stop timer
        stop = time_ns()

        # Calculate execution time
        duration = stop - start

       println("Heap Sort Execution Time: ", duration, " nanoseconds")
       println(file, i, ",", duration)

    end

    close(file)
end
main()
