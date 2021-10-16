#include <bits/stdc++.h>
using namespace std;

class Product {
public:
	double itemPrice;
	double itemWeight;
	double perUnitCost;

	Product(double a, double b) {
		itemPrice = a;
		itemWeight = b;
		perUnitCost = a / b;
	}
};

double perUnitCost(double a, double b) {
	return a / b;
}

bool compare(Product a, Product b)
{
	if (a.perUnitCost > b.perUnitCost) return true;
	return false;
}

pair<double, vector<double>> factionalKnapsak( double knapsakWeight, vector<Product> arr) {

	vector<double> A(arr.size(),0);
	double v = 0;
	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++)
	{
		if (knapsakWeight == 0) {
			pair<double, vector<double>> p;
			p.first = v;
			p.second = A;
			return p;
		}

		double a = min(arr[i].itemWeight, knapsakWeight);
		v = v + a * perUnitCost(arr[i].itemPrice , arr[i].itemWeight);
		A[i] = A[i] + a;
		knapsakWeight = knapsakWeight - a;
	}

	pair<double, vector<double>> p;
	p.first = v;
	p.second = A;
	return p;
}

int main()
{
	vector<Product> arr = {
		Product(20, 4),
		Product(18, 3),
		Product(14, 2)
	};

	auto output = factionalKnapsak(7, arr);

	cout << output.first<<endl;

	vector<double> vec = output.second;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}
