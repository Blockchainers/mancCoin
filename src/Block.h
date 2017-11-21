class Block {
    public:
        int index;
        int proof;
        Transaction transaction;
        String previousHash;
        Block();
        ~Block();
};
