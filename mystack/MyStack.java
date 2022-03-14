public class MyStack {
    private int counter;
    private Object[] stack;

    public MyStack(int size) {
        try {
            stack = new Object[size];
            counter = -1;
        } catch(NegativeArraySizeException nase) {
            throw nase;
        }
    }

    /**
     * @return number of elements on MyStack.
     */
    public int getCounter() { return counter + 1; }

    /**
     * @return String representation of the Object
     */
    public String toString() {
        String s = new String();
        try {
            for(int i = 0; i <= counter; i++) {
                s = s.concat(stack[i] + ";;");
            }
        } catch(NullPointerException npe) {
            throw npe;
        } catch(ArrayIndexOutOfBoundsException aiobe) {
            throw aiobe;
        }
        return s;
    }

    /**
     * This method is used to add an object on the MyStack.
     *
     * @param p the object to put on the MyStack
     */
    public void addElement(Object p) {
        try {
            counter++;
	        stack[counter] = p;
        } catch(NullPointerException npe) {
            counter--;
            throw npe;
        } catch(ArrayIndexOutOfBoundsException aiobe) {
            counter--;
            throw aiobe;
        }
    }

    /**
     * This method is used to resize the MyStack. It is useful if <i>addElement</i> returns an <i>ArrayIndexOutOfBoundsException</i>.
     */
    public void resizeStack() {
        try {
            int newSize = stack.length + 3;
            Object[] newStack = new Object[newSize];
            System.arraycopy(stack, 0, newStack, 0, stack.length);
            stack = newStack;
        } catch(NullPointerException npe) {
            throw npe;
        }
	}

    public static void main(String[] args) {
        Object x = new Object();
        MyStack stack = new MyStack(2);

        stack.addElement(x);
        System.out.println(stack.getCounter());
        System.out.println(stack.toString());

        stack.addElement(x);
        System.out.println(stack.getCounter());
        System.out.println(stack.toString());

        try {
            stack.addElement(x);
            System.out.println(stack.getCounter());
            System.out.println(stack.toString());
        } catch(Exception e) {
            System.out.println("Error Occurred - " + e);
            stack.resizeStack();
        }
        
        stack.addElement(x);
        System.out.println(stack.getCounter());
        System.out.println(stack.toString());
    }
}
