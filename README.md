1. Performance Analysis

The performance of the imgCvtGrayIntoFloat() function, as measured by the average execution time over 100 iterations, shows the following results:

  - 10 x 10 Image Size: 0.000000 seconds
      - The execution time is effectively zero. This is likely due to the function executing too quickly wherein the clock() function cannot measure accurately.
        
  - 100 x 100 Image Size: 0.000040 seconds
      - This indicates that the function is still very fast, but the time taken is now within the measurable range of the clock() function. Given that the time is very small, it reflects the efficiency of the function for moderate-sized images.
        
  - 1000 x 1000 Image Size: 0.003450 seconds
      - As the image size increases, the execution time increases proportionally.

The imgCvtGrayIntoFloat() function performs efficiently across different image sizes. Even for large images (1000 x 1000), the execution time remains in the millisecond range.



2. Screenshot of Outputs
  - 5 x 5 Image Size:
    
    ![image](https://github.com/user-attachments/assets/2510142a-82b4-4491-b944-80d760a9f195)

  - 3 x 6 Image Size:
    
    ![image](https://github.com/user-attachments/assets/efd4bcaa-dc5d-48fc-967f-f72eeaee7999)

  - 7 x 2 Image Size:
    
    ![image](https://github.com/user-attachments/assets/c3f4c9af-c84e-4d83-abf6-461ac9a45d82)

