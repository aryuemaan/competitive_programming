import java.util.Scanner;

class Node {
    int data;
    Node next;
}

class LinkedList {
    Node head;

    public static void main(String[] args) {
        int choice = 0;
        LinkedList list = new LinkedList();
        Scanner scanner = new Scanner(System.in);

        while (choice != 9) {
            System.out.println("\n\n*********Main Menu*********\n");
            System.out.println("Choose one option from the following list ...");
            System.out.println("===============================================");
            System.out.println("1.Insert in beginning\n2.Insert at last\n3.Insert at any random location");
            System.out.println("4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location");
            System.out.println("7.Search for an element\n8.Show\n9.Exit\n");
            System.out.println("Enter your choice?");

            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    list.insertAtBeginning();
                    break;
                case 2:
                    list.insertAtLast();
                    break;
                case 3:
                    list.insertAtRandomLocation();
                    break;
                case 4:
                    list.deleteFromBeginning();
                    break;
                case 5:
                    list.deleteFromLast();
                    break;
                case 6:
                    list.deleteNodeAfterLocation();
                    break;
                case 7:
                    list.search();
                    break;
                case 8:
                    list.display();
                    break;
                case 9:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Please enter valid choice..");
            }
        }

        scanner.close();
    }

    public void insertAtBeginning() {
        Node newNode = new Node();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter value:");
        int item = scanner.nextInt();

        newNode.data = item;
        newNode.next = head;
        head = newNode;

        System.out.println("Node inserted");
    }

    public void insertAtLast() {
        Node newNode = new Node();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter value:");
        int item = scanner.nextInt();

        newNode.data = item;

        if (head == null) {
            newNode.next = null;
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = null;
        }

        System.out.println("Node inserted");
    }

    public void insertAtRandomLocation() {
        Node newNode = new Node();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter element value:");
        int item = scanner.nextInt();
        System.out.println("Enter the location after which you want to insert:");
        int loc = scanner.nextInt();

        newNode.data = item;
        Node temp = head;
        int i = 0;
        while (i < loc) {
            temp = temp.next;
            if (temp == null) {
                System.out.println("Can't insert");
                return;
            }
            i++;
        }
        newNode.next = temp.next;
        temp.next = newNode;

        System.out.println("Node inserted");
    }

    public void deleteFromBeginning() {
        if (head == null) {
            System.out.println("List is empty");
        } else {
            Node ptr = head;
            head = ptr.next;
            ptr = null;
            System.out.println("Node deleted from the beginning");
        }
    }

    public void deleteFromLast() {
        if (head == null) {
            System.out.println("List is empty");
        } else if (head.next == null) {
            head = null;
            System.out.println("Only node of the list deleted");
        } else {
            Node ptr = head;
            Node ptr1 = null;
            while (ptr.next != null) {
                ptr1 = ptr;
                ptr = ptr.next;
            }
            ptr1.next = null;
            ptr = null;
            System.out.println("Deleted Node from the last");
        }
    }

    public void deleteNodeAfterLocation() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the location of the node after which you want to perform deletion:");
        int loc = scanner.nextInt();

        Node ptr = head;
        Node ptr1 = null;
        int i = 0;
        while (i < loc) {
            ptr1 = ptr;
            ptr = ptr.next;

            if (ptr == null) {
                System.out.println("Can't delete");
                return;
            }
            i++;
        }
        ptr1.next = ptr.next;
        ptr = null;
        System.out.println("Deleted node " + (loc + 1));
    }

    public void search() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter item which you want to search:");
        int item = scanner.nextInt();

        Node ptr = head;
        int i = 0;
        boolean flag = false;
        while (ptr != null) {
            if (ptr.data == item) {
                System.out.println("Item found at location " + (i + 1));
                flag = true;
            }
            i++;
            ptr = ptr.next;
        }
        if (!flag) {
            System.out.println("Item not found");
        }
    }

    public void display() {
        if (head == null) {
            System.out.println("Nothing to print");
        } else {
            System.out.println("Printing values...");
            Node ptr = head;
            while (ptr != null) {
                System.out.println(ptr.data);
                ptr = ptr.next;
            }
        }
    }
}
