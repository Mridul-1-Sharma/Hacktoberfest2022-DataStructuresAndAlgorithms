	static class DSU 
	{
	    private int[] parant;
	    private int[] size;

	    public DSU(int N)
	    {
	        parant = new int[N];
	        size = new int[N];
	        for(int i = 0; i < parant.length; i++)
	        {
	            size[i] = 1;
	            parant[i] = i;
	        }
	    }

	    public int root(int i)
	    {
	        while(i != parant[i])
	        {
	            parant[i] = parant[parant[i]];   // this line represents "path compression"
	            i = parant[i];
	        }
	        return i;
	    }

	    public boolean connected(int p, int q)
	    {
	        return root(p) == root(q);
	    }

	    public void union(int p, int q)   // here size[] is used to "weighting"
	    {
	        int i = root(p);
	        int j = root(q);
	        if(i == j) {
	        	// For Aggregate You change Anything
	        	return;
	        }
	        if(size[i] < size[j])
	        {
	            parant[i] = j;
	            size[j] += size[i];
	        }
	        else
	        {
	            parant[j] = i;
	            size[i] += size[j];
	        }
	    }
	}



public static void process() throws IOException {
		DSU dsu = new DSU(100000);
	}
