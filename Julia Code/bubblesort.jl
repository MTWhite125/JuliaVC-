function bubbleSort!(arr, size)

    for i in 1:(size - 1)

        for j in 1:(size - i)

            if arr[j] > arr[j + 1]

                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

            end

        end

    end

end

function main()
    file = open(#=file name=#, "w")
     println(file, "Run,Time (nanoseconds)")
    for i in 1:100

        # Full original array goes here unchanged
        
        arr = #array
        size = length(arr)

        # Start timer
        start = time_ns()

        # Sort array
        bubbleSort!(arr, size)

        # Stop timer
        stop = time_ns()

        # Calculate execution time
        duration = stop - start

       println("Bubble Sort Execution Time: ", duration, " nanoseconds")
       println(file, i, ",", duration)

    end

    close(file)
end
main()
