//6093. Design a Text Editor

class TextEditor {
    // Use a stringbuilder with the cursor location?
    StringBuilder sb = new StringBuilder();
    int cursor = 0;
    
    public TextEditor() {
        
    }
    
    public void addText(String text) {
        sb.insert(cursor, text);
        cursorRight(text.length());
    }
    
    public int deleteText(int k) { // cursor at 4, delete 10
        int currentCursor = cursor;
        sb.delete(Math.max(0, cursor - k), cursor);
        cursorLeft(k);
        return currentCursor - cursor;
    }
    
    public String cursorLeft(int k) {
        cursor = Math.max(0, Math.min(cursor - k, sb.length()));
        return sb.substring(Math.max(0, cursor - 10), cursor).toString();
    }
    
    public String cursorRight(int k) {
        return cursorLeft(-k);
    }
}
