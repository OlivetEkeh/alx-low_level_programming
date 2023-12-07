def is_palindrome(number):
    # Check if the number is a palindrome
    return str(number) == str(number)[::-1]

def largest_palindrome_product():
    largest_palindrome = 0

    # Iterate through all possible products of two 3-digit numbers
    for i in range(100, 1000):
        for j in range(100, 1000):
            product = i * j

            # Check if the product is a palindrome and larger than the current largest palindrome
            if is_palindrome(product) and product > largest_palindrome:
                largest_palindrome = product

    return largest_palindrome

result = largest_palindrome_product()

# Save the result in the specified file
with open("102-result", "w") as file:
    file.write(str(result))
