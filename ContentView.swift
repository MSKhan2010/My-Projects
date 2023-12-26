import SwiftUI

struct ContentView: View {
    
    @State private var isNight = false
        
    var body: some View {
        ZStack {
            
            LinearbackgroundView(isNight: $isNight)
            
            VStack {
                Text("Manchester")
                    .font(.system(size: 32, weight: .medium, design: .default))
                    .foregroundColor(.white)
                    .padding()
                VStack {
                    MainLayoutView(image: isNight ? "moon.stars.fill" : "cloud.sun.fill", temp: "7°")
                    
                    HStack  {
                        
                            WeatherView(dayofWeek: "MON", randImage: "cloud.sun.fill", degrees: 7)
                            WeatherView(dayofWeek: "TUE", randImage: "wind", degrees: 5)
                            WeatherView(dayofWeek: "WED", randImage: "cloud.rain.fill", degrees: 5)
                            WeatherView(dayofWeek: "THUR", randImage: "cloud.fill", degrees: 8)
                            WeatherView(dayofWeek: "FRI", randImage: "sun.fill", degrees: 11)
                    }
                    Spacer()
                    
                    Button {
                        isNight.toggle()
                    } label: {
                        ButtonView(body_text: "Change Day Time", bg_color: Color.white)
                    }
                    Spacer()
                }
            }
        }
    }
    
    struct ContentView_Previews: PreviewProvider {
        static var previews: some View {
            ContentView()
        }
    }
    
    struct WeatherView: View {
        
        var dayofWeek: String
        var randImage: String
        var degrees: Int
        
        var body: some View {
            VStack  {
                Text(dayofWeek)
                    .foregroundColor(.white)
                    .padding()
                    .font(.system(size: 16, weight: .medium, design: .default))
                Image(systemName: randImage)
                    .renderingMode(.original)
                    .resizable()
                    .frame(width: 60, height: 60)
                Text("\(degrees)°")
                    .font(.system(size: 30, weight: .medium, design: .default))
                    .foregroundColor(.white)
                    .aspectRatio(contentMode: .fit)
            }
        }
    }
    
    struct LinearbackgroundView: View {
        
        @Binding var isNight: Bool
        
        var body: some View {
            LinearGradient(gradient: Gradient(colors: [isNight ? .gray : .white, isNight ? .black : .blue]), startPoint: .bottomLeading, endPoint: .topTrailing)
                .edgesIgnoringSafeArea(.all)
        }
    }
    
    struct CityTextView: View {
        
        var CityName: String
        
        var body: some View {
            Text(CityName)
                .font(.system(size: 32, weight: .medium, design: .default))
                .foregroundColor(.white)
                .padding()
        }
    }
    
    struct MainLayoutView: View {
        
        var image: String
        var temp: String
        
        var body: some View {
            VStack {
                Image(systemName: image)
                    .resizable()
                    .renderingMode(.original)
                    .frame(width: 180, height: 180)
                    .aspectRatio(contentMode: .fit)
                
                Text(temp)
                    .padding()
                    .foregroundColor(.white)
                    .aspectRatio(contentMode: .fit)
                    .font(.system(size: 40, weight: .bold, design: .default))
            }
        }
    }
    
    struct ButtonView: View {
        
        var body_text: String
        var bg_color: Color
        
        var body: some View {
            Text(body_text)
                .frame(width: 280, height: 50)
                .background(bg_color)
                .font(.system(size: 20, weight: .bold, design: .default))
                .cornerRadius(10)
        }
    }
}
