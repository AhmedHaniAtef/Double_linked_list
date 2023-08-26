/**
 * @file    : linked_list.c
 * @brief   : implementing linked list data structure
 * @date    : 25 AUG 2023
 * @details : This file contains the defintion of function used with double linked list.
 * @author  : Ahmed Hani Atef
*/

/****************** Start of linking section ***************** */
#include "linked_list.h"
/******************* End of linking section ****************** */

/************* Start of function definition section *************/

static struct node *create_node()
{
    struct node *head = (struct node *)calloc(1, sizeof(struct node));
    if (NULL == head)
    {
        printf("Can't allocate memory for the new node !!");
    }
    else
    {
        head->left = NULL;
        head->right = NULL;
        head->node_data = NULL;
    }
    return head;
}

void insert_at_beginning(struct node **head, void *data)
{
    struct node *TempNode = NULL;
    TempNode = create_node();
    TempNode->node_data = data;
    if (NULL == *head)
    {
        (*head) = TempNode;
    }
    else
    {
        (*head)->left = TempNode;
        TempNode->right = (*head);
        *head = TempNode;
    }
}

void insert_at_end(struct node *head, void *data)
{
    struct node *TempNode = NULL;
    struct node *NodeCounter = NULL;
    TempNode = create_node();
    if(NULL == head)
    {
        printf("Linked List is empty, please use insert_at_begging function\n");
        free(TempNode);
    }
    else
    {
        NodeCounter = head;
        TempNode->node_data = data;
        while (NodeCounter->right != NULL)
        {
            NodeCounter = NodeCounter->right;
        }
        NodeCounter->right = TempNode;
        TempNode->left = NodeCounter;
    }
}

void insert_after(struct node *head, uint32_t position, void *data)
{
    struct node *TempNode = NULL;
    struct node *NodeCounter = NULL;
    TempNode = create_node();
    if(NULL == head)
    {
        printf("Linked List is empty, please use insert_at_begging function\n");
        free(TempNode);
    }
    else
    {
        if (position >= get_length(head))
        {
            printf("Position is out of range, you can use insert_at_end\n");
            free(TempNode);
        }
        else if (position == ZERO)
        {
            printf("please use insert_at_begging instead of insert_after\n");
            free(TempNode);
        }
        else
        {
            TempNode->node_data = data;
            NodeCounter = head;
            while (position != 1)
            {
                NodeCounter = NodeCounter->right;
                position--;
            }
            TempNode->left = NodeCounter;
            TempNode->right = NodeCounter->right;
            NodeCounter->right = TempNode;
            NodeCounter = TempNode->right;
            NodeCounter->left = TempNode;
        }   
    }
}

void insert_before(struct node *head, uint32_t position, void *data)
{
    struct node *TempNode = NULL;
    struct node *NodeCounter = NULL;
    TempNode = create_node();
    if(NULL == head)
    {
        printf("Linked List is empty, please use insert_at_begging function\n");
        free(TempNode);
    }
    else
    {
        if (position > get_length(head))
        {
            printf("Position is out of range, you can use insert_at_end\n");
            free(TempNode);
        }
        else if (position == 1)
        {
            printf("please use insert_at_begging instead of insert_after\n");
            free(TempNode);
        }
        else
        {
            TempNode->node_data = data;
            NodeCounter = head;
            while (position != 1)
            {
                NodeCounter = NodeCounter->right;
                position--;
            }
            TempNode->left = NodeCounter->left;
            TempNode->right = NodeCounter;
            NodeCounter->left = TempNode;
            NodeCounter = TempNode->left;
            NodeCounter->right = TempNode;
        }   
    }
}

void delete_at_beginning(struct node **head)
{
    struct node *TempNode = NULL;
    TempNode = (*head);
    if ((*head) == NULL)
    {
        printf("Linked list is empty, can not delete node\n");
        free(TempNode);
    }
    else
    {
        (*head) = TempNode->right;
        (*head)->left = NULL;
        TempNode->right = NULL;
        TempNode->left = NULL;
        TempNode->node_data = NULL;
        free(TempNode);
    }
}

void delete_at_end(struct node *head)
{
    struct node *TempNode = NULL;
    struct node *NodeCounter = NULL;
    NodeCounter = head;
    if (head == NULL)
    {
        printf("Linked list is empty, can not delete node\n");
        free(NodeCounter);
    }
    else
    {
        while (NodeCounter->right != NULL)
        {
            NodeCounter = NodeCounter->right;
        }
        NodeCounter->node_data = NULL;
        TempNode = NodeCounter->left;
        NodeCounter->left = NULL;
        TempNode->right = NULL;
        free(NodeCounter);
    }
}

void delete_node(struct node **head, uint32_t position)
{
    struct node *TempNode = NULL;
    struct node *NodeCounter = NULL;
    if (head == NULL)
    {
        printf("Linked list is empty, can not delete node\n");
        free(NodeCounter);
    }
    else
    {
        if (position > get_length((*head)))
        {
            printf("position is out of range\n");
        }
        else
        {
            NodeCounter = (*head);
            while ((position != 1))
            {
                if(NodeCounter != NULL)
                {
                    NodeCounter = NodeCounter->right;
                }
                position--;
            }
            if(NodeCounter != NULL)
            {
                if (NodeCounter->left != NULL)
                {
                    TempNode = NodeCounter->left;
                    TempNode->right = NodeCounter->right;
                }
                else
                {
                    (*head) = NodeCounter->right;
                }
                if (NodeCounter->right != NULL)
                {
                    TempNode = NodeCounter->right;
                    TempNode->left = NodeCounter->left;
                    NodeCounter->left = NULL;
                    NodeCounter->right = NULL;
                }
                NodeCounter->node_data = NULL;
                free(NodeCounter);
                NodeCounter = NULL;
            }
        }
    }
}

void display_element(struct node *head, data_type selected_data_type, uint32_t position)
{
    struct node *NodeCounter = NULL;
    if (NULL == head)
    {
        printf("Linked list is empty, please use insert_at_begging to create new node\n");
    }
    else
    {
        if (position > get_length(head))
        {
            printf("Position is out of range\n");
        }
        else
        {
            NodeCounter = head;
            while (position != 1)
            {
                NodeCounter = NodeCounter->right;
                position--;
            }
            switch (selected_data_type)
            {
            case UINT8:
                printf("data in node = %i \n", *((uint8_t *)NodeCounter->node_data));
                break;
            case UINT16:
                printf("data in node = %i \n", *((uint16_t *)NodeCounter->node_data));
                break;
            case UINT32:
                printf("data in node = %i \n", *((uint32_t *)NodeCounter->node_data));
                break;
            case SINT8:
                printf("data in node = %i \n", *((sint8_t *)NodeCounter->node_data));
                break;
            case SINT16:
                printf("data in node = %i \n", *((sint16_t *)NodeCounter->node_data));
                break;
            case SINT32:
                printf("data in node = %i \n", *((sint32_t *)NodeCounter->node_data));
                break;
            case FLOAT32:
                printf("data in node = %0.2f \n", *((float32_t *)NodeCounter->node_data));
                break;
            case FLOAT64:
                printf("data in node = %0.2f \n", *((float64_t *)NodeCounter->node_data));
                break;
            default:
                break;
            }
        }
    }
}

void display_linked_list(struct node *head, data_type selected_data_type, direction dir_of_traversing)
{
    struct node *NodeCounter = head;
    if (NULL == head)
    {
        printf("Linked list is empty, please use insert_at_begging to create new node\n");
    }
    else
    {
        if (FORWARD == dir_of_traversing)
        {
            switch (selected_data_type)
            {
            case UINT8:
                while (1)
                {
                    printf("%i ->", *((uint8_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case UINT16:
                while (1)
                {
                    printf("%i ->", *((uint16_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case UINT32:
                while (1)
                {
                    printf("%i ->", *((uint32_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case SINT8:
                while (1)
                {
                    printf("%i ->", *((sint8_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case SINT16:
                while (1)
                {
                    printf("%i ->", *((sint16_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case SINT32:
                while (1)
                {
                    printf("%i ->", *((sint32_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case FLOAT32:
                while (1)
                {
                    printf("%0.2f ->", *((float32_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            case FLOAT64:
                while (1)
                {
                    printf("%0.2f ->", *((float64_t *)NodeCounter->node_data));
                    if (NodeCounter->right == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->right;
                    }
                }
                printf("NULL\n");
                break;
            default:
                break;
            }
        }
        else
        {
            while (NodeCounter->right != NULL)
            {
                NodeCounter = NodeCounter->right;
            }
            switch (selected_data_type)
            {
            case UINT8:
                while (1)
                {
                    printf("%i ->", *((uint8_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case UINT16:
                while (1)
                {
                    printf("%i ->", *((uint16_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case UINT32:
                while (1)
                {
                    printf("%i ->", *((uint32_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case SINT8:
                while (1)
                {
                    printf("%i ->", *((sint8_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case SINT16:
                while (1)
                {
                    printf("%i ->", *((sint16_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case SINT32:
                while (1)
                {
                    printf("%i ->", *((sint32_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case FLOAT32:
                while (1)
                {
                    printf("%0.2f ->", *((float32_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            case FLOAT64:
                while (1)
                {
                    printf("%0.2f ->", *((float64_t *)NodeCounter->node_data));
                    if (NodeCounter->left == NULL)
                    {
                        break;
                    }
                    else
                    {
                        NodeCounter = NodeCounter->left;
                    }
                }
                printf("NULL\n");
                break;
            default:
                break;
            }
        }
    }
}

void swap_two_nodes(struct node **head, uint32_t first, uint32_t second)
{
    struct node *TempNode = NULL;
    struct node *NodeCounterOne = NULL;
    struct node *NodeCounterTwo = NULL;
    if (NULL == head)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        NodeCounterOne = (*head);
        NodeCounterTwo = (*head);
        while (first != 1)
        {
            NodeCounterOne = NodeCounterOne->right;
            first--;
        }
        while (second != 1)
        {
            NodeCounterTwo = NodeCounterTwo->right;
            second--;
        }
        TempNode = NodeCounterOne->left;
        NodeCounterOne->left = NodeCounterTwo->left;
        NodeCounterTwo->left = TempNode;

        TempNode = NodeCounterOne->right;
        NodeCounterOne->right = NodeCounterTwo->right;
        NodeCounterTwo->right = TempNode;

        if (NodeCounterOne->right != NULL)
        {
            TempNode = NodeCounterOne->right;
            TempNode->left = NodeCounterOne;
        }
        if (NodeCounterOne->left != NULL)
        {
            TempNode = NodeCounterOne->left;
            TempNode->right = NodeCounterOne;
        }
        else
        {
            (*head) = NodeCounterOne;
        }
        if (NodeCounterTwo->right != NULL)
        {
            TempNode = NodeCounterTwo->right;
            TempNode->left = NodeCounterTwo;
        }
        if (NodeCounterTwo->left != NULL)
        {
            TempNode = NodeCounterTwo->left;
            TempNode->right = NodeCounterTwo;
        }
        else
        {
            (*head) = NodeCounterTwo;
        }
    }
}

void remove_duplicated(struct node **head, data_type selected_data_type) /*uncompleted due to multiple warning so i should found a solution for this warning*/
{
    struct node *NodeCounterOne = NULL;
    struct node *NodeCounterTwo = NULL;
    uint32_t CounterOne = 1;
    uint32_t CounterTwo = 1;
    NodeCounterOne = (*head);
    NodeCounterTwo = (*head);
    if(NULL == head)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        while (NodeCounterOne != NULL)
        {
            while (NodeCounterTwo != NULL)
            {
                if(CounterOne == CounterTwo)
                {
                    NodeCounterTwo = NodeCounterTwo->right;
                    CounterTwo++;
                    continue;
                }
                switch (selected_data_type)
                {
                case UINT8:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((uint8_t *)NodeCounterOne->node_data)) == (*((uint8_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case UINT16:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((uint16_t *)NodeCounterOne->node_data)) == (*((uint16_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case UINT32:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((uint32_t *)NodeCounterOne->node_data)) == (*((uint32_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case SINT8:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((sint8_t *)NodeCounterOne->node_data)) == (*((sint8_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case SINT16:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((sint16_t *)NodeCounterOne->node_data)) == (*((sint16_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case SINT32:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((sint32_t *)NodeCounterOne->node_data)) == (*((sint32_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case FLOAT32:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((float32_t *)NodeCounterOne->node_data)) == (*((float32_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                case FLOAT64:
                    if ((NodeCounterOne != NULL) && (NodeCounterTwo != NULL))
                    {
                        if((*((float64_t *)NodeCounterOne->node_data)) == (*((float64_t *)NodeCounterTwo->node_data)))
                        {
                            NodeCounterTwo = NodeCounterTwo->right;
                            delete_node(head,CounterTwo);
                            CounterTwo++;
                            continue;
                        }
                    }
                    break;
                default:
                    break;
                }
                NodeCounterTwo = NodeCounterTwo->right;
                CounterTwo++;
            }
            NodeCounterOne = NodeCounterOne->right;
            NodeCounterTwo = (*head);
            CounterOne++;
            CounterTwo = 1;
        }
        
    }
    NodeCounterOne = NULL;
    NodeCounterTwo = NULL;
    free(NodeCounterOne);
    free(NodeCounterTwo);
}

void merge_two_linked_list(struct node *head_1, struct node *head_2)
{
    struct node *NodeCounter = NULL;
    if ((NULL == head_1) || (NULL == head_2))
    {
        printf("One of the Linked Lists is empty, please use insert_at_begging\n");
    }
    else
    {
        NodeCounter = head_1;
        while (NodeCounter->right != NULL)
        {
            NodeCounter = NodeCounter->right;
        }
        NodeCounter->right = head_2;
        head_2->left = NodeCounter;
    }
}

struct node *split_linked_list(struct node *head, uint32_t position)
{
    struct node *SecondHead = NULL;
    struct node *NodeCounter = NULL;
    if (NULL == head )
    {
        printf("Linked List is empty, please use insert_at_begging at first to create a linked list\n");
        free(SecondHead);
    }
    else
    {
        SecondHead = head;
        while (position != 1)
        {
            SecondHead = SecondHead->right;
            position--;
        }
        NodeCounter = SecondHead->left;
        NodeCounter->right = NULL;
        SecondHead->left = NULL;
    }
    return SecondHead;
}

void *search_data_in_linked_list(struct node *head, data_type selected_data_type, void *data)
{
    struct node *NodeCounter = NULL;
    NodeCounter = head;
    void *retData = NULL;
    uint8_t flag = 0;
    if (NULL == head)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        while (NodeCounter != NULL)
        {
            switch (selected_data_type)
            {
            case UINT8:
                if ((NodeCounter != NULL))
                {
                    if((*((uint8_t *)NodeCounter->node_data)) == (*((uint8_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case UINT16:
                if ((NodeCounter != NULL))
                {
                    if((*((uint16_t *)NodeCounter->node_data)) == (*((uint16_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case UINT32:
                if ((NodeCounter != NULL))
                {
                    if((*((uint32_t *)NodeCounter->node_data)) == (*((uint32_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case SINT8:
                if ((NodeCounter != NULL))
                {
                    if((*((sint8_t *)NodeCounter->node_data)) == (*((sint8_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case SINT16:
                if ((NodeCounter != NULL))
                {
                    if((*((sint16_t *)NodeCounter->node_data)) == (*((sint16_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case SINT32:
                if ((NodeCounter != NULL))
                {
                    if((*((sint32_t *)NodeCounter->node_data)) == (*((sint32_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case FLOAT32:
                if ((NodeCounter != NULL))
                {
                    if((*((float32_t *)NodeCounter->node_data)) == (*((float32_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            case FLOAT64:
                if ((NodeCounter != NULL))
                {
                    if((*((float64_t *)NodeCounter->node_data)) == (*((float64_t *)data)))
                    {
                        flag = 1;
                    }
                }
                break;
            default:
                break;
            }
            if(flag)
            {
                break;
            }
            else
            {
                NodeCounter = NodeCounter->right;
            } 
        }
    }
    if (flag)
    {
        retData = NodeCounter->node_data;
    }
    return (retData);
}

sint32_t search_address_in_linked_list(struct node *head, void *data)
{
    struct node *NodeCounter = NULL;
    NodeCounter = head;
    uint8_t flag = 0;
    sint32_t counter = 1;
    if (NULL == head)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        while (NodeCounter != NULL)
        {
            if(data == NodeCounter->node_data)
            {
                flag = 1;
                break;
            }
            NodeCounter = NodeCounter->right;
            counter++;
        }
    }
    if(!flag)
    {
        counter = -1;
    }
    return (counter);
}

uint32_t get_length(struct node *head)
{
    uint32_t counter = ZERO;
    struct node *NodeCounter = NULL;
    NodeCounter = head;
    if (NULL == head)
    {
        counter = ZERO;
    }
    else
    {
        while (NodeCounter != NULL)
        {
            counter++;
            NodeCounter = NodeCounter->right;
        }
    }
    return counter;
}

void destroy_linked_list(struct node **head)
{
    struct node *NodeCounter = NULL;
    if (NULL == (*head))
    {
        printf("Linked List is empty already\n");
    }
    else
    {
        NodeCounter = (*head);
        while (NULL != NodeCounter)
        {
            NodeCounter->node_data = NULL;
            free(NodeCounter->left);
            NodeCounter->left = NULL;
            NodeCounter = NodeCounter->right;
        }
        free(NodeCounter);
        NodeCounter = NULL;
    }
}

/************** End of function defintion section **************/

/*===================================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   -----------------------------------------------------------------------------
    25 AUG 2023     Ahmed Hani Atef     Creating of linked_list.c file and writing the defintion of some functions.
    26 AUG 2023     Ahmed Hani Atef     Completing the definition of the functions
====================================================================================================================*/