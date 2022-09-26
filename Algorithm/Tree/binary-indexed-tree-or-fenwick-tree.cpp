class BITree
{
public:
    vector<ll> Tree;
    int sizeTree;
public:           // Access specifier
    BITree(int n)       // Constructor
    {
        sizeTree=n+1;
        Tree.clear();
        Tree.resize(sizeTree+5,0);
    }
    BITree(ll arr[],int n)       // Constructor
    {
        sizeTree=n+1;
        Tree.clear();
        Tree.resize(sizeTree+5,0);
        for (int i=0; i<n; i++)
            update(i, arr[i]);
    }
    BITree(vector<ll> arr)       // Constructor
    {
        sizeTree=arr.size()+1;
        Tree.clear();
        Tree.resize(sizeTree+5,0);
        for (int i=0; i<sizeTree-1; i++)
            update(i, arr[i]);
    }

    void update(int index,ll val)
    {
        index = index + 1;

        while (index <= sizeTree)
        {

            Tree[index] += val;

            index += index & (-index);
        }

    }

    ll getSum(int toIndex)
    {
        ll sum = 0;

        toIndex = toIndex + 1;

        while (toIndex>0)
        {
            sum += Tree[toIndex];

            toIndex -= toIndex & (-toIndex);
        }
        return sum;
    }

    ll getSumRange(int fromIndex,int toIndex)
    {
        if(fromIndex<1)
        {
            return getSum(toIndex);
        }
        return getSum(toIndex)-getSum(fromIndex-1);
    }

    void printTree()
    {
        for(auto item:Tree)
        {
            cout<<item<<"  ";
        }
        cout<<endl;
    }

    void printSumArray()
    {
        for(int i=0; i<sizeTree; i++)
        {
            cout<<getSum(i)<<"  ";
        }
        cout<<endl;
    }

    void printRealArray()
    {
        cout<<getSum(0)<<"  ";
        for(int i=1; i<sizeTree; i++)
        {
            cout<<getSum(i)-getSum(i-1)<<"  ";
        }
        cout<<endl;
    }


};