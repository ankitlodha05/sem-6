#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> symptoms = {"Fever", "Cough", "Headache", "Sore throat","Shortness of breath","Chest pain","Fatigue","Nausea","Vomiting","Dehydration","Increased thirst"," Blurred vision","Weight loss","Abdominal Cramps"};

unordered_map<string, vector<string>> diseases = {
    {"Common Cold", {"Fever", "Cough", "Headache", "Sore throat"}},
    {"Flu", {"Fever", "Cough", "Headache"}},
    {"Strep Throat", {"Fever", "Sore throat"}},
    {"Migraine", {"Headache"}},
    {"Pneumonia", {"Fever", "Cough", "Shortness of breath", "Chest pain", "Fatigue", "Confusion", "Nausea", "Vomiting"}},
    {"Gastroenteritis", {"Diarrhea", "Nausea", "Vomiting", "Abdominal cramps", "Fever", "Blood in stool", "Dehydration"}},
    {"Diabetes", {"Increased thirst", "Frequent urination", "Extreme hunger", "Unexplained weight loss", "Fatigue", "Irritability", "Blurred vision", "Slow-healing sores"}},
    {"Hypertension", {"Headaches", "Shortness of breath", "Nosebleeds", "Dizziness", "Chest pain", "Vision changes"}},
    {"Otitis Media (Ear Infection)", {"Ear pain", "Tugging or pulling at the ear", "Difficulty sleeping", "Fussiness in infants and young children", "Fever", "Fluid drainage from the ear"}},
    {"Meningitis", {"Sudden high fever", "Stiff neck", "Severe headache", "Headache with nausea or vomiting", "Confusion or difficulty concentrating", "Seizures", "Sleepiness or difficulty waking up", "Sensitivity to light"}},
    {"Hyperthyroidism", {"Weight loss", "Rapid heartbeat (tachycardia)", "Irregular heartbeat (arrhythmia)", "Increased appetite", "Nervousness", "Anxiety", "Irritability", "Tremor (shaking) in hands and fingers", "Sweating"}}
};

unordered_map<string, vector<string>> doctor_recommendations = {
    {"General Practitioner (GP)", {"Common Cold", "Flu", "Strep Throat", "Pneumonia", "Urinary Tract Infection (UTI)", "Gastroenteritis", "Hypertension", "Otitis Media (Ear Infection)"}},
    {"Pulmonologist", {"Pneumonia"}},
    {"Gastroenterologist", {"Gastroenteritis"}},
    {"Endocrinologist", {"Diabetes", "Hyperthyroidism"}},
    {"Neurologist", {"Migraine", "Meningitis"}},
    {"ENT Specialist", {"Strep Throat", "Otitis Media (Ear Infection)"}},
    {"Cardiologist", {"Hypertension"}}
};

vector<string> get_user_input() {
    vector<string> user_symptoms;
    for (const string& symptom : symptoms) {
        char response;
        cout << "Do you have " << symptom << "? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            user_symptoms.push_back(symptom);
        }
    }
    return user_symptoms;
}

void diagnose() {
    vector<string> user_symptoms = get_user_input();
    set<string> possible_diseases;
    
    for(int i=0;i<user_symptoms.size();i++){
        string symptom=user_symptoms[i];
        for(auto i:diseases){
            string d=i.first;
            vector<string> cause=i.second;
            if(find(cause.begin(),cause.end(),symptom)!=cause.end()){
                possible_diseases.insert(d);
            }
        }
    }

    if (!possible_diseases.empty()) {
        cout << "Possible diseases:" << endl;
        for (const string& disease_name : possible_diseases) {
            cout << "- " << disease_name << endl;
        }

        // Find the most probable disease based on the number of matching symptoms
        string most_probable_disease;
        int max_matching_symptoms = 0;
        for (const string& disease_name : possible_diseases) {
            int matching_symptoms = count_if(diseases[disease_name].begin(), diseases[disease_name].end(), [&](const string& symptom) {
                return find(user_symptoms.begin(), user_symptoms.end(), symptom) != user_symptoms.end();
            });
            if (matching_symptoms > max_matching_symptoms) {
                most_probable_disease = disease_name;
                max_matching_symptoms = matching_symptoms;
            }
        }

        cout << "\nMost probable disease based on symptoms: " << most_probable_disease << endl;

        // Find recommended doctor for the most probable disease
        cout << "\nRecommended doctor(s) to consult for the most probable disease:" << endl;
        for (const auto& recommendation : doctor_recommendations) {
            const string& doctor = recommendation.first;
            const vector<string>& specialties = recommendation.second;
            if (find(specialties.begin(), specialties.end(), most_probable_disease) != specialties.end()) {
                cout << "- " << doctor << endl;
            }
        }
    } else {
        cout << "No matching diseases found." << endl;
    }
}

int main() {
    diagnose();
    return 0;
}
