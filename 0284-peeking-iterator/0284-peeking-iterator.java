class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> iterator;
    private Integer peeked;
    
    public PeekingIterator(Iterator<Integer> iterator) {
        this.iterator = iterator;
        this.peeked = null;
    }
    
    public Integer peek() {
        if (peeked == null) {
            peeked = iterator.next();
        }
        
        return peeked;
    }
    
    @Override
    public Integer next() {
        if (peeked != null) {
            Integer result = peeked;
            peeked = null;
            return result;
        }
        
        return iterator.next();
    }
    
    @Override
    public boolean hasNext() {
        return peeked != null || iterator.hasNext();
    }
}