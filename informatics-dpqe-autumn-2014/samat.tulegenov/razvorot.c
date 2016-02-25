class Node
    {
        public void SetNextNode(Node _nextNode)
        {
            this.next = _nextNode;
        }
        public int Element
        { 
            get
            {
                return this.element;
            }
            set
            {
                this.element = value;
            }
        }
 
        public Node Next
        {
            get
            {
                return this.next;
            }
        }
 
        private Node next;
        private int element;
    }
 
class List
    {
        public List()
        {
            this.headNode = null;
            this.tailNode = this.headNode;
            this.Length = 0;
        }
        public void Push(int _element)
        {
            if (headNode == null)
            {
                this.headNode = new Node();
                this.headNode.Element = _element;
                this.tailNode = this.headNode;
                this.headNode.SetNextNode(null);
            }
            else
            {
                Node newNode = new Node();
                this.tailNode.SetNextNode(newNode);
                this.tailNode = newNode;
                this.tailNode.Element = _element;
                this.tailNode.SetNextNode(null);
            }
 
            ++this.Length;
        }
        public int this[int _position]
        {
            get
            {
                Node tempNode = this.headNode;
                for (int i = 0; i < _position; ++i)
                  
                    tempNode = tempNode.Next;
                return tempNode.Element;
            }
        }
 
        public int Length { get; private set; }
        private Node headNode;
        private Node tailNode;
    }

