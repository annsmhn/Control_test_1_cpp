#include <iostream>
using namespace std;
//������� ������ ������, ����� �������� � ������� ������ ������
template <typename T> class Vector3DPolar
    {
    #include <cmath>
    private:
        T x,y,z;
        T r;
        double phi;
        double tetra;
        //�������� ��������� ���������� �� ��������
        T getX_cartesian_3d() {
            return x = r * cos(phi) * sin(tetra);
        }
        T getY_cartesian_3d() {
            return y = r * sin(phi) * sin(tetra);
        }
        T getZ_cartesian_3d() {
            return z = r * cos(phi);
        }
    public:
        // ����������� �� ���������
        Vector3DPolar() : r(0), tetra(0), phi(0){}
        // ����������� � �����������
        Vector3DPolar(T radius, float zenith, float azimuth)
            : r(radius), tetra(zenith), phi(azimuth) {
        }       
        // ������� ����� �������
        void input_polar_vector() {
            cout << "������� ������-������ (r): ";
            cin >> r;
            cout << "������� �������� ���� (theta, � ��������): ";
            cin >> tetra;
            cout << "������� ������������ ���� (phi, � ��������): ";
            cin >> phi;
        }
        // ������� ������ �������
        void display_polar_vector() const {
            cout << "�������� ����������: r = " << r
                << ", theta = " << tetra
                << ", phi = " << phi << std::endl;
        }
        //��-�� ��������� �������, ���������� ������ ������, �.�. ��� ���������� � ����� ����� ��� ������� ����� for
        void display_cartesian_vector(T value)
        {
            #include <cmath>
            x = abs((int)getX_cartesian_3d());
            y = abs((int)getY_cartesian_3d());
            z = abs((int)getZ_cartesian_3d());
            for (int i = 1; i <= x; i++)
            {
                for (int j = 1; j <= y; j++)
                {
                    for (int k = 1; k <= z; k++)
                    {
                        cout<<value<<" ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
};
int main() {
    setlocale(LC_ALL, "");
    Vector3DPolar<int> v1(11,27.0f,4.1f);
    v1.display_cartesian_vector(3);
    //�������� ����������� ��������� ��� ����� 11,27.,4.1 
    Vector3DPolar<int> v2;
    v2.input_polar_vector();
    v2.display_polar_vector();
    v2.display_cartesian_vector(3);
    return 0;
}