function fn(arr):  
        left = 0  
        for right in [0, arr.length - 1]:  
            Do some logic to "add" element at arr[right] to window  
            while left < right AND condition from problem not met:  
                Do some logic to "remove" element at arr[left] from window  
                left++  
            Do some logic to update the answer  
