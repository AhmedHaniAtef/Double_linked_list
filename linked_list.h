/**
 * @file    : linked_list.h
 * @brief   : implementing linked list data structure
 * @date    : 25 AUG 2023
 * @details : This file contains the declaration of function used with double linked list.
 * @author  : Ahmed Hani Atef
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/****************** Start of linking section ***************** */
#include "platform_types.h"
/******************* End of linking section ****************** */

/********************* Start of data types *********************/

/**
 * @brief   the basic structure of doubly linked list
 */
struct node
{
    struct node *left;
    struct node *right;
    void *node_data;
};

/**
 *  @brief  this enum is used as data type specifier for displaying the data in a
            linked list of different data types
*/
typedef enum
{
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    SINT8,
    SINT16,
    SINT32,
    SINT64,
    FLOAT32,
    FLOAT64
} data_type;

typedef enum
{
    FORWARD,
    BACKWARD
}direction;
/*********************** End of data types ***********************/

/************* Start of function declaration section *************/
/**
 * @brief   insert a node at beginning
 * @param   head pointer to the address of the head of linked list
 * @param   data a pointer to the inserted data
*/
void insert_at_beginning(struct node **head, void *data);

/**
 * @brief   insert a node at end
 * @param   head pointer to head of linked list
 * @param   data a pointer to the inserted data
*/
void insert_at_end(struct node *head, void *data);

/**
 * @brief   insert a node after position
 * @param   head pointer to the address of the head of linked list
 * @param   data a pointer to the inserted data
 * @param   position a variable stores the index of inserting after 
*/
void insert_after(struct node *head, uint32_t position, void *data);

/**
 * @brief   insert a node before position
 * @param   head pointer to the address of the head of linked list
 * @param   data a pointer to the inserted data
 * @param   position a variable stores the index of inserting before 
*/
void insert_before(struct node *head, uint32_t position, void *data);

/**
 * @brief   delete a node at beginning
 * @param   head pointer to the address of the head of linked list
*/
void delete_at_beginning(struct node **head);

/**
 * @brief   delete a node at end
 * @param   head pointer to the head of linked list
*/
void delete_at_end(struct node *head);

/**
 * @brief   delete a node at specific position
 * @param   head pointer to the head of linked list
 * @param   position a variable stores the index of deleted node
*/
void delete_node(struct node **head, uint32_t position);

/**
 * @brief   display a node of specific position
 * @param   head pointer to the head of linked list
 * @param   position a variable stores the index of displayed node
 * @param   selected_data_type a variable of data type enum "data_type" to choose to print the data at node in which data type
*/
void display_element(struct node *head, data_type selected_data_type, uint32_t position);

/**
 * @brief   display whole linked list
 * @param   head pointer to the head of linked list
 * @param   dir_of_traversing a variable stores the direction of printing "forward or backward"
 * @param   selected_data_type a variable of data type enum "data_type" to choose to print the data 
*/
void display_linked_list(struct node *head, data_type selected_data_type, direction dir_of_traversing);

/**
 * @brief   swap two nodes in linked list
 * @param   head pointer to the address of the head of linked list
 * @param   first a variable stores the position of first node to be swapped
 * @param   second a variable stores the position of second node to be swapped
*/
void swap_two_nodes(struct node **head, uint32_t first, uint32_t second);

/**
 * @brief   remove duplicated nodes in linked list
 * @param   head pointer to the address of the head of linked list
 * @param   selected_data_type a variable stores the data type to be compared in the function to delete duplicated data
*/
void remove_duplicated(struct node **head, data_type selected_data_type);

/**
 * @brief   merge two linked lists into one 
 * @param   head_1 pointer to the head of first linked list and after execution of the function it pointed to the new merged linked list
 * @param   head_2 pointer to the head of second linked list and after execution of the function it pointed to the new merged linked list
*/
void merge_two_linked_list (struct node *head_1 ,struct node *head_2);

/**
 * @brief   split a linked list into two 
 * @param   head pointer to the head of linked list and after execution of the function it pointed to the second splitted linked list
 * @retval  it returns a pointer to the first splitted linked list
*/
struct node *split_linked_list (struct node *head, uint32_t position);

/**
 * @brief   search data in linked list with specific data type
 * @param   head pointer to the head of linked list 
 * @param   selected_data_type a variable stores the data type of searched data
 * @param   data a pointer to the data to search in the linked list 
*/
void *search_data_in_linked_list(struct node *head, data_type selected_data_type, void *data);

/**
 * @brief   destroy the linked list
 * @param   head pointer to the address of the head of linked list 
*/
void destroy_linked_list(struct node **head);

/**
 * @brief   search address in linked list 
 * @param   head pointer to head of linked list 
 * @param   data a pointer to the search in the linked list
 * @retval  it returns 1 if it is found and -1 if not 
*/
sint32_t search_address_in_linked_list(struct node *head, void *data);

/**
 * @brief   get the length of the linked list
 * @param   head pointer to the head of linked list 
 * @retval  it returns the length of the linked list
*/
uint32_t get_length (struct node *head);
/************** End of function declaration section **************/
#endif

/*===================================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   -----------------------------------------------------------------------------
    25 AUG 2023     Ahmed Hani Atef     Creating of linked_list.h file and writing the declaration of the functions.

====================================================================================================================*/