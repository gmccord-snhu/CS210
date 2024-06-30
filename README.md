# CS210
CS210 Class Projects

## BankApp Project

**Summarize the project and what problem it was solving.**

The project at Chada Tech involves collaborating with Airgead Banking to develop an application aimed at teaching high school students fiscal responsibility, specifically focusing on concepts like living within their means and understanding compound interest. The application's primary goal is to provide an interactive platform where users can visualize how their investments grow over time. This initiative is part of Airgead Banking's community engagement efforts, particularly through their sponsorship of schools, to promote financial literacy among students.

**What did you do particularly well?**
I was able to deliver the application to its specifications, despite the complexity of calculations involved with interest payments over time. Concerns were well encapsulated into individual functions that kept the main() routine very light and easily customizable.

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**
The areas I felt needed improvement were rounding, especially around rounding float values in currency. The specification did not offer much guidance in this regard, and I would expect the bank would want to have exact requirements about how numbers are rounded. This ensures the bank is not losing money or undercutting customer's savings. Ultimately, I decided to leave it alone and use some rough rounding calculations - but this is an area that needs improvement in the code.

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

Calculating the compound added interest monthly was particularly challenging. I think I rewrote that part of the code several times since my outputs did not match the example. To find help, I researched the topic in an Internet search engine to better understand the math.

What skills from this project will be particularly transferable to other projects or course work?

Keeping the main() routine as short and simple as possible really helps understand the program. This was not something I was too concerned about at the start of the course. Now that I see the benefits, I will certainly continue this practice going forward.

**How did you make this program maintainable, readable, and adaptable?**

Code was separated into distinct classes, each with its header files. Functions were provided for each part of the program and encapsulated complexity. Also, good comments were written for each function and part of the program so subsequent authors would understand what was done and why. Standard code formatting was also used to make the code readable.


