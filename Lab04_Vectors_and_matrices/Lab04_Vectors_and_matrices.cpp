#include <iostream>

// Include the glm library
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>

int main() {
    //vectors
    printf("Vectors and matrices\n");
    printf("----------------------\n");

    //defining a vector
    glm::vec3 a, b;
    a = glm::vec3(3.0f, 0.0f, 4.0f);
    b[0] = 1.0f, b[1] = 2.0f, b[2] = 3.0f;

    printf("Defining vectors:\n");
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    //Vector length
    printf("Vector length:\n");
    printf("Length of a = %0.3f\n", glm::length(a));
    printf("Length of b = %0.3f\n", glm::length(b));

    //Vector normalization
    glm::vec3 aHat, bHat;
    aHat = glm::normalize(a);
    bHat = b / glm::length(b);

    printf("\nVector normalization:\n");
    std::cout << "aHat = " << aHat << std::endl;
    std::cout << "bHat = " << bHat << std::endl;
    printf("length(aHat) = %0.3f\n", glm::length(aHat));
    printf("length(bHat) = %0.3f\n", glm::length(bHat));

    //Arithmetic operations
    printf("\nArithmetic operations:\n");
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "2a    = " << 2.0f * a << std::endl;
    std::cout << "b / 3 = " << b / 3.0f << std::endl;
    std::cout << "a * b = " << a * b << std::endl;

    //Dot and cross product
    printf("\nDot and cross product:\n");
    printf("a . b = %0.3f\n", glm::dot(a, b));

    std::cout << "a x b = " << glm::cross(a, b) << std::endl;
    printf("a . (a x b) = %0.3f\n", glm::dot(a, glm::cross(a, b)));
    printf("b . (a x b) = %0.3f\n", glm::dot(b, glm::cross(a, b)));

    //defining matrices
    glm::mat2 A, B;

    A[0][0] = 1.0f, A[0][1] = 2.0f;
    A[1][0] = 3.0f, A[1][1] = 4.0f;

    B = glm::mat2(5.0f, 6.0f, 7.0f, 8.0f);

    printf("\nDefining matrices:\n");
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;

    std::cout << "A= " << glm::transpose(A) << "\n" << std::endl;
    std::cout << "B= " << glm::transpose(B) << "\n" << std::endl;

    //arithmetic operations on matrices
    printf("\nArithmetic operations on matrices:\n");
    std::cout << "A + B = " << glm::transpose(A + B) << "\n" << std::endl;
    std::cout << "A - B = " << glm::transpose(A - B) << "\n" << std::endl;
    std::cout << "2A    = " << glm::transpose(2.0f * A) << "\n" << std::endl;
    std::cout << "A / 3 = " << glm::transpose(A / 3.0f) << "\n" << std::endl;

    std::cout << "A * B = " << glm::transpose(B * A) << "\n" << std::endl;
    std::cout << "B * A = " << glm::transpose(A * B) << "\n" << std::endl;

    //the identity matrix
    printf("\nThe identity matrix:\n");
    glm::mat4 I;
    std::cout << "I = " << glm::transpose(I) << "\n" << std::endl;

    //Inverse of a matrix
    printf("\nInverse of a matrix:\n");
    glm::mat2 invA = glm::inverse(A);
    glm::mat2 invB = glm::inverse(B);
    std::cout << "invA = " << glm::transpose(invA) << "\n" << std::endl;
    std::cout << "invB = " << glm::transpose(invB) << "\n" << std::endl;
    std::cout << "invA * A = " << glm::transpose(A * invA) << "\n" << std::endl;
    std::cout << "invB * B = " << glm::transpose(B * invB) << "\n" << std::endl;

    //exercises
    //exercise 1
    //a)

    return 0;
}
