#include <bits/stdc++.h>
using namespace std;

class Product {
    static int productIdGenerator;
    int productId;
    string productName;
    int productPrice;

public:
    Product() 
    {
        productId = productIdGenerator++;
        productName = "";
        productPrice = 0;
    }
    
    int getProductId() {
        return productId;
    }
    
    string getProductName() {
        return productName;
    }
    
    void setProductName(string name) {
        productName = name;
    }
    
    int getProductPrice() {
        return productPrice;
    }
    
    void setProductPrice(int price) {
        productPrice = price;
    }
};

int Product::productIdGenerator = 1;

class Seller {
    static int sellerIdGenerator;
    int sellerId;
    string sellerName;
    string sellerPassword;
    vector<Product> sellerProductList;

public:
    Seller() {
        sellerId = sellerIdGenerator++;
        sellerName = "";
        sellerPassword = "";
        sellerProductList = vector<Product>();
    }

    int getSellerId() {
        return sellerId;
    }
    
    string getSellerName() {
        return sellerName;
    }
    
    void setSellerName(string name) {
        sellerName = name;
    }
    
    string getSellerPassword() {
        return sellerPassword;
    }
    
    void setSellerPassword(string password) {
        sellerPassword = password;
    }
    
    vector<Product>& getSellerProductList() {
        return sellerProductList;
    }
    
    void addItem(Product product) {
        sellerProductList.push_back(product);
    }
    
    void updateItem(int productId, Product updatedProduct) {
        for (auto& product : sellerProductList) {
            if (product.getProductId() == productId) {
                product = updatedProduct;
                break;
            }
        }
    }
};

int Seller::sellerIdGenerator = 1;

class User {
    static int userIdGenerator;
    int userId;
    string userName;
    string userPassword;
    vector<Product> userCartList;
    vector<Product> userBuyList;

public:
    User() : userId(userIdGenerator++) {}

    int getUserId() {
        return userId;
    }
    
    string getUserName() {
        return userName;
    }
    
    void setUserName(string name) {
        userName = name;
    }
    
    string getUserPassword() {
        return userPassword;
    }
    
    void setUserPassword(string password) {
        userPassword = password;
    }
    
    vector<Product>& getUserCartList() {
        return userCartList;
    }
    
    vector<Product>& getUserBuyList() {
        return userBuyList;
    }
};

int User::userIdGenerator = 1;

class Manager {
    vector<Product> allProductList;
    vector<Seller> sellerList;
    vector<User> userList;

public:

        void registerSeller()
        {
            Seller s;
            string sname;string password;
            cout<<"Enter Seller Name : ";
            cin>>sname;
            cout<<"Enter New Password : ";
            cin>>password;
            cout<<"Keep your password safe for future login\n";
            s.setSellerName(sname);
            s.setSellerPassword(password);
            sellerList.push_back(s);
            cout<<"Seller succesfully registerd\n";
            cout<<"-------------------------- \n";
            // display()//display pannu lets check if working;
        }
        void registerSeller(string name,string password)	//dummy
        {
        	Seller s;
        	s.setSellerName(name);
        	s.setSellerPassword(password);
        	sellerList.push_back(s);
        	addProduct(s, "dummy", 100 );
		}
		
		
        void loginSeller()
        {
            string sname,password;
            cout<<"Enter Seller Name : ";cin>>sname;
            cout<<"Enter Seller Password : ";cin>>password;
            bool sellerFound = 0;
            Seller* selectedSeller = nullptr;
            for(Seller &seller : sellerList)
            {
                selectedSeller = &seller;
                if(sname == selectedSeller->getSellerName() && password == selectedSeller->getSellerPassword())
                {
                    sellerFound = 1;
                    cout<<"Welcome Back, "<<sname<<", with ID : "<<selectedSeller->getSellerId()<<endl;
                    // addProduct(seller);
                    //view, add, delete product
                    
                    bool sellerLoop = 1;
                    
                    while(sellerLoop)
                    {
                        cout<<"Choose from below \n1. Add New Product \n2. Update Existing Product \n3. LogOut";
                        int sellerChoice;
                        cin>>sellerChoice;
                        switch(sellerChoice)
                        {
                            case 1:
                                    addProduct(seller);
                                    break;
                            case 2:
                                    updateProduct(seller);
                                    break;
                            case 3:
                                    sellerLoop = false;
                                    cout<<"\nWell be waiting, add more products, enjoy\n"<<"--------------------------\n";
                                    break;
                            default:
                                    cout<<"\nInvalid choice please choose again\n";
                                    break;
                        }
                    }
                }
            }
            if(!sellerFound)
            {
                cout<<"Your SellerName or Password is Invalid, please try again\n";
            }
        }
        
        void displaySellers()
        {
            Seller* selectedSeller = nullptr;
            for(Seller &seller : sellerList)
            {
                selectedSeller = &seller;
                cout<<"Seller ID : "<<selectedSeller->getSellerId()<<", SellerName : "<<selectedSeller->getSellerName()<<", No. of Products : "<<endl;
            }
        }
        
        
        void addProduct(Seller &s)
        {
            Seller* selectedSeller = nullptr;
            selectedSeller = &s;
            
            cout<<"Enter Product Name : ";string name;cin>>name;
            cout<<"Enter Price of the product : ";int price;cin>>price;
            Product p;
            p.setProductName(name);
            p.setProductPrice(price);
            selectedSeller->getSellerProductList().push_back(p);
            allProductList.push_back(p);
            cout<<"Product with ID : "<<p.getProductId()<<" has been added to the list\n";
            cout<<"--------------------------\n";
            
        }
        void addProduct(Seller &s, string name, int price)			//dummy
		{
			Seller* selectedSeller = nullptr;
			selectedSeller = &s;
			Product p;
            p.setProductName(name);
            p.setProductPrice(price);
            selectedSeller->getSellerProductList().push_back(p);
            allProductList.push_back(p);
		}
        
        void updateProduct(Seller &s)
        {
            bool productFound = 0;
            Product * selectedProduct = nullptr;
            cout<<"Enter ProductID you want to update : ";int productId;cin>>productId;
            vector<Product> k = s.getSellerProductList();
            for(Product& product : k)
            {
                selectedProduct = &product;
                if(selectedProduct->getProductId() == productId)
                {
                    productFound = 1;
                    string productName;
                    int updatePrice;
                    cout<<"Product Found, \n1. Update Name\n2. Update Price\n";
                    int updateChoice;cin>>updateChoice;
                    if(updateChoice == 1 )
                    {
                        cin>>productName;
                        selectedProduct->setProductName(productName);
                        cout<<"\nUpdated product name to : "<<productName<<endl;
                    }
                    else if(updateChoice == 2)
                    {
                        cin>>updatePrice;
                        selectedProduct->setProductPrice(updatePrice);
                        cout<<"\nUpdated product price\n";
                    }
                    
                    for(Product &p : allProductList)
                    {
                        if(p.getProductId() == productId)
                        {
                            if(updateChoice == 1)
                            {
                                p.setProductName(productName);
                            }
                            else if(updateChoice == 2)
                            {
                                p.setProductPrice(updatePrice);
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            
            if(!productFound)
            {
                cout<<"\nProduct with ID not found\n";
            }
        }
        

        
        void displayAllProducts()
        {
            Product *selectedProduct = nullptr;
            for(Product &product : allProductList)
            {
                selectedProduct = &product;
                cout<<"Product ID : "<<selectedProduct->getProductId()<<", Product Name : "<<selectedProduct->getProductName()<<", Price : "<<selectedProduct->getProductPrice()<<endl;
                cout<<"--------------------------\n";
            }
        }
        
        void registerUser()
        {
            cout<<"Enter User Name : ";
            string uname;cin>>uname;
            cout<<"Enter New User Password : ";
            string password;cin>>password;
            User u;
            u.setUserName(uname);
            u.setUserPassword(password);
            userList.push_back(u);
            cout<<u.getUserName() <<" registered with ID : "<<u.getUserId()<<endl;
        }
        
        void loginUser()
        {
            cout<<"Enter User Name : ";
            string name,password;cin>>name;
            cout<<"Enter password : ";cin>>password;
            
            User* selectedUser = nullptr;
            bool userFound = 0;
            for(User& user : userList)
            {
                selectedUser = &user;
                if(selectedUser->getUserName() == name && selectedUser->getUserPassword() == password)
                {
                    userFound = 1;
                    bool userLoop = true;
                    while(userLoop)
                    {
                        cout<<"\nChoose an action \n1. View Products \n2. View Cart \n3. Add to Cart \n4. BuyProduct \n5. Check Out Cart\n6. LogOut\n";
                        int userChoice;
                        cin>>userChoice;
                        switch(userChoice)
                        {
                            case 1:
                            {
                                displayAllProducts();
                                break;
                            }
                            case 2:
                            {
                            	checkUpdate(user);
                                viewCart(user);
                                break;
                            }
                            case 3:
                            {
                                addtoCart(user);
                                break;
                            }
                            case 4:
                            {
                                buyProduct(user);
                                break;
                            }
                            case 5:
                            {
                            	checkOut(user);
                            	break;
							}
                            case 6: 
                            {
                                cout<<"Comeback again and buy crazy products\n -------------------------- \n";
                                userLoop = false;
                                break;
                            }
                            default:
                                cout<<"Invalid choice please choose again\n";
                                break;
                        }
                    }
                    break;
                }
            }
            if(!userFound)
            {
                cout<<"\nInvalid userName or password\n";
            }
            
            cout<<"--------------------------";
        }
        
        
        void checkUpdate(User &u)
        {
        	Product *selectedProduct = nullptr;
        	for(Product &p : u.getUserCartList())
        	{
        		selectedProduct = &p;
        		for(Product &p : allProductList)
        		{
        			if(selectedProduct->getProductId() == p.getProductId())
        			{
        				if(selectedProduct->getProductName() != p.getProductName()) selectedProduct->setProductName(p.getProductName());
						if(selectedProduct->getProductPrice() != p.getProductPrice()) selectedProduct->setProductPrice(p.getProductPrice());  
					}
				}
			}
		}
        
        
        void viewCart(User &u)
        {
            Product* selectedProduct = nullptr;
            for(Product &p : u.getUserCartList())
            {
                selectedProduct = &p;
                cout<<"Product ID : "<<selectedProduct->getProductId()<<", Product Name : "<<selectedProduct->getProductName() << ", Price : "<<selectedProduct->getProductPrice()<<endl;
            }
        }
        void addtoCart(User &u)
        {
            cout<<"Enter Product ID you want to add : ";
            int productId;cin>>productId;
            bool productFound = 0;
            for(Product& p : allProductList)
            {
                productFound = 1;
                if(p.getProductId() == productId)
                {
                    productFound = 1;
                    u.getUserCartList().push_back(p);
                    cout<<p.getProductName()<<" with ID : "<< p.getProductId() <<"Added to Cart";
                }
            }
            if(!productFound)
            {
                cout<<"Invalid productId\n";
            }
        }
        void buyProduct(User &u)
        {
            cout<<"\nEnter Product ID you want to buy : ";
            int productId;cin>>productId;
            bool productFound = 0;
            for(Product &p : allProductList)
            {
            	if(p.getProductId() == productId)
            	{
            		productFound = 1;
            		cout<<"Product Name : "<<p.getProductName()<<", Product Price : "<<p.getProductPrice()<<"\nPress 1 if youre sure else press any other key\n";
            		char v;cin>>v;if(v!='1')break;
            		cout<<"\nThanks for buying the product.\n";
				}
			}
			if(!productFound)
			{
				cout<<"\nInvalid product\n";
			}
        }
        
        void checkOut(User &u)
        {
        	User* selectedUser = nullptr;
        	selectedUser = &u;
        	cout<<"\nProducts in cart\n";
        	int sum=0;
        	for(Product &p : selectedUser->getUserCartList())
        	{
        		cout<<"Product ID : "<<p.getProductId()<<", Name : "<<p.getProductName()<<", Price : "<<p.getProductPrice()<<endl;
        		sum+=p.getProductPrice();
			}
			cout<<"\nTotal amount to pay : "<<sum;
			cout<<"Press 1 to make Payment or press any other to cancel\n";
			char v;cin>>v;if(v!='1'){cout<<"Process cancelled\n";}
			else cout<<"\nPayment Succesful\nThanks for buying.\n";
			
		}












    vector<Product>& getAllProductList() {
        return allProductList;
    }
    
    vector<Seller>& getSellerList() {
        return sellerList;
    }
    
    vector<User>& getUserList() {
        return userList;
    }
};

int main() {
    Manager manager;
    manager.registerSeller("Seller1", "pass");
    manager.registerSeller("Seller2", "pass");
    bool mainLoop = true;
    
    while(mainLoop)
    {
        cout<<"Choose any one \n1. User \n2. Seller \n3. Display All Products \n4. Exit\n";
        int mainChoice;
        cin>>mainChoice;
        
        switch(mainChoice)
        {
            case 1:
            {
                cout<<"\n1. Register User \n2. Login User\n";
                int UserChoice;
                cin>>UserChoice;
                switch(UserChoice)
                {
                    case 1:
                            manager.registerUser();
                            break;
                    case 2:
                            manager.loginUser();
                            break;
                    // case 3:
                    //         manager.displayAllProducts();
                    //         break;
                    
                    default:
                            cout<<"\nInvalid choice please choose again\n";
                            break;
                }
                break;
            }
            case 2:
            {
                cout<<"\n1. Register Seller \n2. Login Seller\n";
                int sellerChoice;
                cin>>sellerChoice;
                switch(sellerChoice)
                {
                    case 1:
                            manager.registerSeller();
                            break;
                    case 2:
                            manager.loginSeller();
                            break;
                    // case 3:
                    //         manager.displayAllProducts();
                    //         break;
                    
                    default:
                            cout<<"\nInvalid choice please choose again\n";
                            break;
                }
                break;
            }
            case 3:
                    manager.displayAllProducts();
                    break;
            case 4:
                    mainLoop = false;
                    cout<<"Exit";
            default:
                    cout<<"\nInvalid choice please choose again\n";
                    break;
        }
    }
}
