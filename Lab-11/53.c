
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node *link;
} ;

int createNode(int coeff, int power) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;
    return newNode;
}

void insertTerm(struct Node **FIRST, int coeff, int power) {
    if (coeff == 0) 
        return; 

    struct Node *newNode = createNode(coeff, power);

    if (*FIRST == NULL) {
        *FIRST = newNode;
        return;
    }

    struct Node *temp = *FIRST;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = newNode;
}

struct Node* readPolynomial() {
    struct Node *FIRST = NULL;
    int n, coeff, power;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Term %d - Enter coefficient and power: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertTerm(&FIRST, coeff, power);
    }
    return FIRST;
}


struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power == poly2->power) {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else if (poly1->power > poly2->power) {
            insertTerm(&result, poly1->coeff, poly1->power);
            poly1 = poly1->link;
        }
        else {
            insertTerm(&result, poly2->coeff, poly2->power);
            poly2 = poly2->link;
        }
    }

    
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->power);
        poly1 = poly1->link;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->power);
        poly2 = poly2->link;
    }

    return result;
}

void printPolynomial(struct Node *FIRST) {
    if (FIRST == NULL) {
        printf("0\n");
        return;
    }

    struct Node *temp = FIRST;
    int first = 1;

    while (temp != NULL) {
        if (!first && temp->coeff > 0)
            printf(" + ");
        else if (temp->coeff < 0)
            printf(first ? "-" : " - ");

        if (temp->power == 0)
            printf("%d", abs(temp->coeff));
        else if (temp->power == 1)
            printf("%dx", abs(temp->coeff));
        else
            printf("%dx^%d", abs(temp->coeff), temp->power);

        first = 0;
        temp = temp->link;
    }
    printf("\n");
}

int main() {
     struct Node *poly1, *poly2, *sum;

    printf("=== Enter First Polynomial ===\n");
    poly1 = readPolynomial();

    printf("\n=== Enter Second Polynomial ===\n");
    poly2 = readPolynomial();

    sum = addPolynomials(poly1, poly2);

    printf("\nPolynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    printf("sum         : ");
    printPolynomial(sum);

    return 0;
}